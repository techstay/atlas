from agents import (
    Agent,
    Runner,
    set_default_openai_api,
    set_default_openai_client,
)
from openai import AsyncOpenAI

from ai_demos.utils import ark_config_mini as config


def helloworld():
    client = AsyncOpenAI(
        base_url=config.base_url,
        api_key=config.api_key,
    )
    set_default_openai_client(client, use_for_tracing=False)
    set_default_openai_api("chat_completions")
    agent = Agent(
        name="helloworld",
        instructions="You are a helpful assistant.",
        model=config.model,
    )

    result = Runner.run_sync(
        agent,
        "What's the capital of Japan?",
    )
    print(result.final_output)


if __name__ == "__main__":
    helloworld()
