from typing import List, Set, Dict

import openai
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
    def __init__(self, program: Program, prompt_dir: str, cache: str, model: str):
        openai.api_key = os.getenv("OPENAI_API")

        self.program = program
        self.prompt_dir = prompt_dir
        self.prompt_id = 0

        self.model = model

        if cache is not None:
            self.cache = join(cache, "prompts/")
        else:
            self.cache = None
        models = openai.Model.list()
        #print(models)

        self.line_number_to_predicate: Dict[int, Dict[str, int]] = {}
        self.line_number_to_assertion_to_predicate: Dict[int, Dict[str, Predicate]] = {}

    @staticmethod
    def create_message(content: str, system = False):
        return {"role": "system" if system else "user", "content": content}

    # , model="gpt-3.5-turbo"
    def prompt(self, messages, model: str, max_tokens=100, attempts = 1, penalty = 1.5):
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
                    model=model,
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
        if line_number is None:
            return []

        message, assertion_points = self.create_message_for_assertion_point(goal, line_number, attributes, num_assertions)
        name_to_line_number = {}
        for k, v in assertion_points.items():
            name_to_line_number[v] = k
        messages.append(message)
        if simulate:
            self.dump_messages(messages)
            exit(0)
        else:
            self.dump_messages(messages)
            raw_result = ""
            results = []
            for penalty in [1.5, 2]:
                for d in self.prompt(messages, attempts=attempts, penalty=penalty, model=self.model)["choices"]:
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
                if "?" in result:
                    candidates = self.rewrite_case_split_into_disjunction(result, simulate)
                    if len(candidates) > 0:
                        result = candidates[0]
                    else:
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

                    end_of_loop_line_number = line_number
                    while end_of_loop_line_number not in self.program.assertion_points or \
                            AssertionPointAttributes.EndOfLoop not in self.program.assertion_points[end_of_loop_line_number]:
                        end_of_loop_line_number += 1
                    predicate2 = copy(self.line_number_to_assertion_to_predicate[line_number][x])
                    predicate2.line_number = end_of_loop_line_number

                    candidates.append([self.line_number_to_assertion_to_predicate[line_number][x],
                                       predicate])

                    #candidates.append([predicate2,
                    #                   self.line_number_to_assertion_to_predicate[line_number][x]])
                else:
                    candidates.append([self.line_number_to_assertion_to_predicate[line_number][x]])

            self.line_number_to_predicate = dict()
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
            for penalty in [1.5 , 2]:
                for d in self.prompt(messages, attempts=attempts, penalty=penalty, model=self.model)["choices"]:
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
                if "?" in result:
                    candidates = self.rewrite_case_split_into_disjunction(result, simulate)
                    if len(candidates) > 0:
                        result = candidates[0]
                    else:
                        continue
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
        content_end = (f"Use '&&' or '||' if necessary. Prefer equality over inequality. "
                       f"Don't explain. Your answer should be 'assert(...); // line name'")
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
                                f"Print loop invariants as valid C assertions at line A"
                                f". "
                                #f" that helps prove the assertion. "
                                f"")
                content_end = (f"Use '&&' or '||' if necessary. Prefer equality over inequality. "
                               f"Don't explain. Your answer should be 'assert(...); // line A'")
                content = content_head + content_end
            else:
                for i, line in enumerate(lines):
                    assertion_points[line] = name[i]
                content = (f"{self.program.get_program_with_assertion(goal, [], assertion_points, forGPT=True)}\n"
                           f"Print loop invariants as valid C assertions at "
                           f"lines {', '.join([assertion_points[line] for line in lines])}"
                           f". ") + content_end
        else:
            lines = []
            for assertion_point, items in self.program.assertion_points.items():
                if assertion_point < line_number and AssertionPointAttributes.InLoop in items:
                    lines.append(assertion_point)
            lines.append(line_number)
            for i, line in enumerate(lines):
                assertion_points[line] = name[i]
            content = (f"{self.program.get_program_with_assertion(goal, [], assertion_points, forGPT=True)}\n"
                       f"Print facts as valid C assertions at lines {', '.join([assertion_points[line] for line in lines])}. "
                       f"Don't use loop variables at line {assertion_points[line_number]}. ") + content_end

        return self.create_message(content, system=False), assertion_points

    def create_message_for_adapt(self, goal : Predicate, current_subgoal : Predicate, falsified: bool):
        attributes = self.program.assertion_points[current_subgoal.line_number]
        assertion_points = {current_subgoal.line_number: "A"}
        if AssertionPointAttributes.InLoop in attributes:
            content_head = f"{self.program.get_program_with_assertion(goal, [], assertion_points, forGPT=True)}\n"
            content_head += f"Print loop invariants as valid C assertions at line A. "
            if falsified:
                content = f"Your previous answer '{current_subgoal.content}' is incorrect. "
            else:
                content = f"Your previous answer '{current_subgoal.content}' is too weak. "
            content_end = (f"Use '&&' or '||' if necessary. "
                           f"Don't explain. Your answer should simply be 'assert(...);'")
            content = content_head + content + content_end
        else:
            content_head = f"{self.program.get_program_with_assertion(goal, [], assertion_points, forGPT=True)}\n"
            content_head += f"Print facts as valid C assertions at line A. "
            if falsified:
                content = f"Your previous answer '{current_subgoal.content}' is incorrect. "
            else:
                content = f"Your previous answer '{current_subgoal.content}' is too weak. "
            content_end = (f"Use '&&' or '||' if necessary. "
                           f"Don't explain. Your answer should simply be 'assert(...);'")
            content = content_head + content + content_end
        return self.create_message(content, system=False)

    def rewrite_case_split_into_disjunction(self, result: str, simulate: bool):
        print("Assertion contains `?`, ask GPT to rewrite.")
        messages = []
        message = self.create_message(f"Get rid of the ternary operator. Don't explain. "
                                      f"Your answer should simply be 'assert(...);'.", system=True)
        messages.append(message)

        message = self.create_message((f"assert(b == (a >= 18) ? 0 : b + a); => assert((a >= 18 && b == 0) || (a < 18 && b == b + a));\n"
                                       f"assert(c > 0 && x  + (a  < 1  ? 1 : 2) == 3); => assert(c > 0 && (a < 1 && x  + 1== 3) || (a >= 1 && x + 2 == 3));\n"
                                       f"assert({result}); => "), system=False)
        messages.append(message)
        if simulate:
            self.dump_messages(messages)
            exit(0)
        else:
            self.dump_messages(messages)
            raw_result = ""
            results = []
            for d in self.prompt(messages, attempts=1, model=self.model)["choices"]:
                raw_result += f"GPT output {d['index'] + 1}:\n{d['message']['content']}\n"
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
            return results

    @staticmethod
    def dump_messages(messages):
        print("\nDumping messages...")
        for message in messages:
            print(f"{bold(message['role'])}:\n{message['content']}")

        print("\nDumping messages - done")