from dotenv import load_dotenv
from langfuse.decorators import observe
from openai import OpenAI
from phoenix.otel import register

from ai_demos.utils import ark_config_mini as config

load_dotenv()

# configure phoenix tracer
tracer_provider = register(
    auto_instrument=True,
)


def completion_api():
    client = OpenAI(
        api_key=config.api_key,
        base_url=config.base_url,
    )
    response = client.chat.completions.create(
        model=config.model,
        messages=[
            {
                "role": "system",
                "content": "You are a helpful assistant. You should answer question shortly and briefly",
            },
            {"role": "user", "content": "What's the famous 10 city in the world?"},
        ],
        stream=True,
        stream_options={"include_usage": True},
    )
    for chunk in response:
        if chunk.choices:
            print(chunk.choices[0].delta.content, end="")

    print()


# Currently only OpenAI supports response API
@observe
def response_api():
    client = OpenAI(
        api_key=config.api_key,
        base_url=config.base_url,
    )
    response = client.responses.create(
        model=config.model,
        instructions="You are a helpful assistant.",
        input="What's the famous 10 city in the world?",
        stream=True,
    )
    for event in response:
        print(event)


if __name__ == "__main__":
    completion_api()
