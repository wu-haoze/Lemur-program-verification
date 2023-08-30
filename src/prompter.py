from typing import List, Set

import openai
import os
from program import Program, AssertionPointAttributes
from predicate import Predicate
from time import perf_counter
import json
from utils import *
import re
from os.path import join, isfile
from copy import copy


class Prompter:
    def __init__(self, program: Program, prompt_dir: str, cache: str):
        openai.api_key = os.getenv("OPENAI_API")

        self.program = program
        self.prompt_dir = prompt_dir
        self.prompt_id = 0

        if cache is not None:
            self.cache = join(cache, "prompts/")
        else:
            self.cache = None
        models = openai.Model.list()
        #print(models)
        #self.prompt([self.create_message("how are you?")], max_tokens=5, attempts = 1)



    @staticmethod
    def create_message(content: str, system = False):
        return {"role": "system" if system else "user", "content": content}

    def prompt(self, messages, max_tokens=150, attempts = 1, penalty = 1.5):
        start = perf_counter()
        self.prompt_id += 1
        prompt_filename = f"prompt{self.prompt_id}.json"
        if self.cache is not None and isfile(join(self.cache, prompt_filename)):
            print("Prompt cached!")
            with open(join(self.cache, prompt_filename), 'r') as f:
                result = json.load(f)
            with open(os.path.join(self.prompt_dir, prompt_filename), 'w') as out_file:
                json.dump(result, out_file)
            return result
        else:
            try:
                result = openai.ChatCompletion.create(
                    #model="gpt-3.5-turbo",
                    model="gpt-4",
                    messages=messages,
                    temperature=0.5,
                    max_tokens=max_tokens,
                    n = attempts,
                    presence_penalty = penalty,
                    frequency_penalty = penalty,
                )
            except Exception as e:
                print("Error: ", e)
                result = {}
            elapsed = perf_counter() - start
            result["elapsed"] = elapsed
            result["messages"] = messages
            with open(os.path.join(self.prompt_dir, prompt_filename), 'w') as out_file:
                json.dump(result, out_file)
            return result

    def suggest_predicate(self, goal: Predicate, num_assertions: int, attempts: int,
                          simulate=True)-> List[List[Predicate]]:
        messages = []
        message = self.create_message(f"You understand C program well.", system=True)
        messages.append(message)

        line_number, attributes = self.program.decide_assertion_point(goal)
        message = self.create_message_for_assertion_point(goal, line_number, attributes, num_assertions)
        messages.append(message)
        if simulate:
            self.dump_messages(messages)
            exit(0)
        else:
            self.dump_messages(messages)
            raw_result = ""
            results = []
            for penalty in [1, 2]:
                for d in self.prompt(messages, attempts=attempts, penalty=penalty)["choices"]:
                    raw_result += f"GPT output {d['index'] + 1} with penality {penalty}:\n{d['message']['content']}\n"
                    tmp_results = []
                    for line in d['message']['content'].split("\n"):
                        result = re.findall(r'assert\((.*?)\);', line)
                        if len(result) > 0:
                            tmp_results.append(result[0])
                        else:
                            continue
                    results += tmp_results[-3:]

            raw_result = raw_result[:-1]
            print(f"{raw_result}")
            assertions = dict()
            assertion_to_candidate = dict()
            for result in results:
                key = None
                for a in assertions:
                    if check_equivalence(a, result):
                        key = a
                        break
                if key is not None:
                    assertions[key] += 1
                else:
                    assertions[result] = 1
                    predicate = Predicate(result, line_number)
                    assertion_to_candidate[result] = predicate
            print(assertions)
            # Sort based on occurrence, break tie by picking shorter one
            sorted_assertions = sorted(assertions.keys(), key=lambda x: (assertions[x], -len(x)), reverse=True)
            candidates = []
            for x in sorted_assertions:
                candidates.append([assertion_to_candidate[x]])
                if AssertionPointAttributes.BeginningOfLoop in attributes and \
                        ("while " in self.program.lines[line_number] or "do " in self.program.lines[line_number]):
                    # we are adding an assumption to the beginning of the while loop, might as well add it right before
                    # the while loop
                    predicate = copy(assertion_to_candidate[x])
                    predicate.line_number = line_number - 1
                    candidates.append([assertion_to_candidate[x], predicate])
            return candidates

    def create_message_for_assertion_point(self, goal : Predicate, line_number: int,
                                           attributes: Set[AssertionPointAttributes],
                                           num_assertions: int):

        if AssertionPointAttributes.InLoop in attributes:
            lines = []
            num_loops = 0
            for assertion_point, items in self.program.assertion_points.items():
                if assertion_point <= line_number and AssertionPointAttributes.InLoop in items:
                    lines.append(assertion_point + 1)
                    if AssertionPointAttributes.BeginningOfLoop in items:
                        num_loops += 1
            if num_loops == 1:
                if AssertionPointAttributes.BeforeAssertion in attributes:
                    content_head = (f"{self.program.get_program_with_assertion(goal, [], forGPT=True)}\n"
                                   f"Print {num_assertions} loop invariants right before the assertion "
                                   f"that help prove it. ")
                else:
                    content_head = (f"{self.program.get_program_with_assertion(goal, [], forGPT=True)}\n"
                                    f"Print {num_assertions} loop invariants right after line {line_number + 1} "
                                    f"that help prove the assertion. ")
                content_end = (f"If there are multiple, print them as a single assertion using '&&'. "
                              f"Don't explain. Your answer should simply be 'line {line_number + 1}: assert(...);'")
                content = content_head + content_end
            else:
                content = (f"{self.program.get_program_with_assertion(goal, [], forGPT=True)}\n"
                           f"Print all loop invariants after lines {', '.join(map(str, lines))} about x "
                           f"that help prove the assertion. "
                           f"If there are multiple, print them as a single assertion using '&&'. "
                           f"Don't explain. Your answer should simply be 'line number: assert(...);'")
        elif AssertionPointAttributes.BeforeLoop in attributes:
            lines = []
            for assertion_point, items in self.program.assertion_points.items():
                if assertion_point < line_number and AssertionPointAttributes.InLoop in items:
                    lines.append(assertion_point + 1)
            lines.append(line_number + 1)
            content = (f"{self.program.get_program_with_assertion(goal, [], forGPT=True)}\n"
                       f"Print facts after lines {', '.join(map(str, lines))} "
                       f"that help prove the assertion. "
                       f"If there are multiple, print them as a single assertion using '&&'. "
                       f"Don't explain. Your answer should simply be 'line number: assert(...);'")

        return self.create_message(content, system=False)

    @staticmethod
    def dump_messages(messages):
        print("\nDumping messages...")
        for message in messages:
            print(f"{bold(message['role'])}:\n{message['content']}")

        print("\nDumping messages - done")