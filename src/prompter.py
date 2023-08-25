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
        #models = openai.Model.list()
        #self.prompt([self.create_message("how are you?")], max_tokens=5, attempts = 1)



    @staticmethod
    def create_message(content: str, system = False):
        return {"role": "system" if system else "user", "content": content}

    def prompt(self, messages, max_tokens=100, attempts = 1):
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
                    model="gpt-3.5-turbo",
                    messages=messages,
                    temperature=0.5,
                    max_tokens=max_tokens,
                    n = attempts,
                    presence_penalty = 1,
                    frequency_penalty = 1,
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

    def suggest_predicate(self, goal: Predicate, num_assertions: int, attempts: int,  simulate=True):
        messages = []
        message = self.create_message(f"You understand C program well. "
                                      f"Your answer should be 'assert(...);'", system=True)
        messages.append(message)

        line_number, attributes = self.program.decide_assertion_point(goal)
        message = self.create_message_for_assertion_point(goal, line_number, attributes, num_assertions)
        messages.append(message)

        if simulate:
            self.dump_messages(messages)
        else:
            self.dump_messages(messages)
            raw_result = ""
            for d in self.prompt(messages, attempts=attempts)["choices"]:
                raw_result += f"GPT output {d['index'] + 1}:\n{d['message']['content']}\n"
            print(f"{raw_result}")
            result = re.findall(r'assert\((.*?)\);', raw_result)
            assertions = dict()
            assertion_to_candidate = dict()
            for r in result:
                if r in assertions:
                    assertions[r] += 1
                else:
                    assertions[r] = 1
                    predicate = Predicate(r, line_number)
                    assertion_to_candidate[r] = predicate
            sorted_assertions = sorted(assertions.keys(), key=lambda x: assertions[x], reverse=True)
            candidates = [assertion_to_candidate[x] for x in sorted_assertions]
            return candidates

    def create_message_for_assertion_point(self, goal : Predicate, line_number: int,
                                           attributes: Set[AssertionPointAttributes],
                                           num_assertions: int):
        if AssertionPointAttributes.InLoop in attributes:
            object = "loop invariants"
        else:
            object = "invariants"

        if AssertionPointAttributes.BeforeAssertion in attributes:
            location = f"right before the assertion"
        elif AssertionPointAttributes.InLoop in attributes:
            location = f"right after line {line_number}"
        else:
            location = f"right before line {line_number + 1}"

        content = (f"{self.program.get_program_with_assertion(goal, [], forGPT=True)}\n"
                   f"List {num_assertions} different {object} as C assert statements "
                   f"{location} that helps prove the assertion. Don't explain.")
        return self.create_message(content, system=False)

    @staticmethod
    def dump_messages(messages):
        print("\nDumping messages...")
        for message in messages:
            print(f"{bold(message['role'])}:\n{message['content']}")

        print("\nDumping messages - done")