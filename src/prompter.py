import openai
import os
from program import Program
from predicate import Predicate
from time import perf_counter
import json

class Prompter:
    def __init__(self, program: Program, prompt_dir: str):
        openai.api_key = os.getenv("OPENAI_API")

        self.program = program
        self.prompt_dir = prompt_dir
        self.prompt_id = 0

        #models = openai.Model.list()
        #self.prompt([self.create_message("how are you?")], max_tokens=5, attempts = 1)



    @staticmethod
    def create_message(content: str, system = False):
        return {"role": "system" if system else "user", "content": content}

    def prompt(self, messages, max_tokens=10, attempts = 5):
        start = perf_counter()
        self.prompt_id += 1
        try:
            result = openai.ChatCompletion.create(
               model="gpt-3.5-turbo",
               messages=messages,
               temperature=0,
               max_tokens=max_tokens,
               n = attempts
            )
        except Exception as e:
            print("Error: ", e)
            result = {}
        print(result)
        elapsed = perf_counter() - start
        result["elapsed"] = elapsed
        result["messages"] = messages
        with open(os.path.join(self.prompt_dir, f"prompt{self.prompt_id}.txt"), 'w') as out_file:
            json.dump(result, out_file)


    def ask_for_predicate_at_line(self, goal: Predicate, line_number: int):
        messages = []
        message = self.create_message(f"You are an insightful C analyzer. Provide as succinct answers as possible.", system=True)
        messages.append(message)


        closest_line = 0
        for assertion_point in self.program.assertion_points:
            if line_number > assertion_point > closest_line:
                closest_line = assertion_point

        message = self.create_message("List 5 different C assert statements after line {closest_line} "
                                      "that helps prove the assertion.", system=False)
        messages.append(message)
        response = openai.ChatCompletion.create(
          model="gpt-3.5-turbo",
          messages=messages,
          temperature=0,
        )

