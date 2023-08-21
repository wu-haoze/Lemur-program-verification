import openai
import os

api_key = os.getenv("OPENAI_API")
openai.api_key = api_key
print(api_key)

models = openai.Model.list()
print(models)

response = openai.ChatCompletion.create(
  model="gpt-3.5-turbo",
  messages=[ {"role": "system", "content":
              """
              Just testing.
              """
              },
             {"role": "user",
             "content":
              """
              How are you?
              """
             }
  ],
  temperature=0,

)

print(response)
