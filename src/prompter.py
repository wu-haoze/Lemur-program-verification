from typing import List, Set, Dict

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

replacements = {"UCHAR_MAX": "0xff", "UINT_MAX": "0xffffffff"}

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

        self.line_number_to_predicate: Dict[int, Dict[str, int]] = {}
        self.line_number_to_assertion_to_predicate: Dict[int, Dict[str, Predicate]] = {}

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
                    temperature=0.8,
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
        message, assertion_points = self.create_message_for_assertion_point(goal, line_number, attributes, num_assertions)
        name_to_line_number = {}
        for k, v in assertion_points.items():
            name_to_line_number[v] = k
        name = assertion_points[line_number]
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
                            tmp_results.append((line[-1], result[0]))
                        else:
                            continue
                    results += tmp_results

            raw_result = raw_result[:-1]
            print(f"{raw_result}")

            for line_name, result in results:
                key = None
                if line_name not in name_to_line_number:
                    continue
                for k, v in replacements.items():
                    result = result.replace(k, v)
                tmp_line_number = name_to_line_number[line_name]
                if tmp_line_number not in self.line_number_to_predicate:
                    self.line_number_to_predicate[tmp_line_number] = dict()
                    self.line_number_to_assertion_to_predicate[tmp_line_number] = dict()

                for a in self.line_number_to_predicate[tmp_line_number]:
                    if check_equivalence(a, result):
                        key = a
                        break
                if key is not None:
                    self.line_number_to_predicate[tmp_line_number][key] += 1
                else:
                    self.line_number_to_predicate[tmp_line_number][result] = 1
                    predicate = Predicate(result, tmp_line_number)
                    self.line_number_to_assertion_to_predicate[tmp_line_number][result] = predicate
            print(self.line_number_to_predicate)
            print(self.line_number_to_assertion_to_predicate)
            # Sort based on occurrence, break tie by picking shorter one
            sorted_assertions = sorted(self.line_number_to_predicate[line_number].keys(),
                                       key=lambda x: (self.line_number_to_predicate[line_number][x], -len(x)), reverse=True)
            candidates = []
            for x in sorted_assertions:
                if AssertionPointAttributes.BeginningOfLoop in attributes and \
                        ("while " in self.program.lines[line_number] or "do " in self.program.lines[line_number]):
                    # we are adding an assumption to the beginning of the while loop, might as well add it right before
                    # the while loop
                    predicate = copy(self.line_number_to_assertion_to_predicate[line_number][x])
                    predicate.line_number = line_number - 1
                    candidates.append([self.line_number_to_assertion_to_predicate[line_number][x], predicate])
                else:
                    candidates.append([self.line_number_to_assertion_to_predicate[line_number][x]])
            return candidates

    def adapt_predicate(self, goal: Predicate, current_sub_goal: Predicate, falsified : bool,
                        attempts: int, simulate=True)-> List[List[Predicate]]:
        messages = []
        message = self.create_message(f"You understand C program well.", system=True)
        messages.append(message)

        message = self.create_message_for_adapt(goal, current_sub_goal, falsified)
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
                    results += tmp_results

            raw_result = raw_result[:-1]
            print(f"{raw_result}")

            # clear the previous proof goal
            self.line_number_to_predicate[current_sub_goal.line_number] = dict()
            self.line_number_to_assertion_to_predicate[current_sub_goal.line_number] = dict()
            for result in results:
                key = None
                for a in self.line_number_to_predicate[current_sub_goal.line_number]:
                    if check_equivalence(a, result):
                        key = a
                        break
                if key is not None:
                    self.line_number_to_predicate[current_sub_goal.line_number][key] += 1
                else:
                    self.line_number_to_predicate[current_sub_goal.line_number][result] = 1
                    predicate = Predicate(result, current_sub_goal.line_number)
                    self.line_number_to_assertion_to_predicate[current_sub_goal.line_number][result] = predicate
            print(self.line_number_to_predicate)
            print(self.line_number_to_assertion_to_predicate)
            # Sort based on occurrence, break tie by picking shorter one
            sorted_assertions = sorted(self.line_number_to_predicate[current_sub_goal.line_number].keys(),
                                       key=lambda x: (self.line_number_to_predicate[current_sub_goal.line_number][x], -len(x)), reverse=True)
            candidates = []
            for x in sorted_assertions:
                if "while " in self.program.lines[current_sub_goal.line_number] \
                        or "do " in self.program.lines[current_sub_goal.line_number]:
                    # we are adding an assumption to the beginning of the while loop, might as well add it right before
                    # the while loop
                    predicate = copy(self.line_number_to_assertion_to_predicate[current_sub_goal.line_number][x])
                    predicate.line_number = current_sub_goal.line_number - 1
                    candidates.append([self.line_number_to_assertion_to_predicate[current_sub_goal.line_number][x], predicate])
                else:
                    candidates.append([self.line_number_to_assertion_to_predicate[current_sub_goal.line_number][x]])
            return candidates

    def create_message_for_assertion_point(self, goal : Predicate, line_number: int,
                                           attributes: Set[AssertionPointAttributes],
                                           num_assertions: int):
        assertion_points = {}
        name = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"]
        if AssertionPointAttributes.InLoop in attributes:
            lines = []
            num_loops = 0
            for assertion_point, items in self.program.assertion_points.items():
                if assertion_point <= line_number and AssertionPointAttributes.InLoop in items:
                    lines.append(assertion_point)
                    if AssertionPointAttributes.BeginningOfLoop in items:
                        num_loops += 1
            if num_loops == 1:
                assertion_points[line_number] = "A"
                content_head = (f"{self.program.get_program_with_assertion(goal, [], assertion_points, forGPT=True)}\n"
                                f"Print loop invariants as C assertions at line A "
                                f"that help prove the assertion. ")
                content_end = (f"Use '&&' or '||' if necessary. Prefer equality over inequality. "
                               f"Don't explain. Your answer should simply be 'assert(...); // line A'")
                content = content_head + content_end
            else:
                for i, line in enumerate(lines):
                    assertion_points[line] = name[i]
                content = (f"{self.program.get_program_with_assertion(goal, [], assertion_points, forGPT=True)}\n"
                           f"Print loop invariants as C assertions at lines {', '.join([assertion_points[line] for line in lines])} "
                           f"that help prove the assertion. "
                           f"Use '&&' or '||' if necessary. Prefer equality over inequality. "
                           f"Don't explain. Each line of your answer should be 'assert(...); // line name'")
        elif AssertionPointAttributes.BeforeLoop in attributes:
            lines = []
            for assertion_point, items in self.program.assertion_points.items():
                if assertion_point < line_number and AssertionPointAttributes.InLoop in items:
                    lines.append(assertion_point)
            lines.append(line_number)
            for i, line in enumerate(lines):
                assertion_points[line] = name[i]
            content = (f"{self.program.get_program_with_assertion(goal, [], assertion_points, forGPT=True)}\n"
                       f"Print facts as C assertions at lines {', '.join([assertion_points[line] for line in lines])} "
                       f"that help prove the assertion. "
                       f"Don't use loop variables at line {assertion_points[line_number]}. "
                       f"Use '&&' or '||' if necessary. Prefer equality over inequality. "
                       f"Don't explain. Each line of your answer should be 'assert(...); // line name'")

        return self.create_message(content, system=False), assertion_points

    def create_message_for_adapt(self, goal : Predicate, current_subgoal : Predicate, falsified: bool):
        attributes = self.program.assertion_points[current_subgoal.line_number]
        assertion_points = {current_subgoal.line_number: "A"}
        if AssertionPointAttributes.InLoop in attributes:
            content_head = f"{self.program.get_program_with_assertion(goal, [], assertion_points, forGPT=True)}\n"
            content_head += f"Print loop variants as C assertions at line A that help prove the assertion. "
            if falsified:
                content = f"Correct your previous answer '{current_subgoal.content}'. "
            else:
                content = f"Strengthen your previous answer '{current_subgoal.content}'. "

            content_end = (f"Use '&&' or '||' if necessary. Prefer equality over inequality. "
                           f"Don't explain. Your answer should simply be 'assert(...);'")
            content = content_head + content + content_end
        else:
            content_head = f"{self.program.get_program_with_assertion(goal, [], assertion_points, forGPT=True)}\n"
            content_head += f"Print facts as C assertions at line A that help prove the assertion. "
            if falsified:
                content = f"Correct your previous answer '{current_subgoal.content}'. "
            else:
                content = f"Strengthen you previous answer '{current_subgoal.content}'. "

            content_end = (f"Use '&&' or '||' if necessary. Prefer equality over inequality. "
                           f"Don't explain. Your answer should simply be 'assert(...);'")
            content = content_head + content + content_end
        return self.create_message(content, system=False)



    @staticmethod
    def dump_messages(messages):
        print("\nDumping messages...")
        for message in messages:
            print(f"{bold(message['role'])}:\n{message['content']}")

        print("\nDumping messages - done")