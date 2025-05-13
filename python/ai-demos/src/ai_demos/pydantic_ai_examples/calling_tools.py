from pydantic_ai import Agent, RunContext

from ai_demos.pydantic_ai_examples.utils import (
    configure_and_get_pydantic_ai_provider,
)

agent = Agent(
    configure_and_get_pydantic_ai_provider(),
    system_prompt="You are a helpful assistant. If you need to get the weather, please use the `get_weather` tool. ",
)


@agent.tool
def get_weather(ctx: RunContext, city: str) -> str:
    """Get the weather in a given city"""
    import random

    weathers = "rainy snowy sunny windy foggy stormy".split(" ")
    return random.choice(weathers)


def main():
    result = agent.run_sync(
        "What's the weather in Shanghai?",
    )
    print(result.output)

    result = agent.run_sync(
        "What's the weather in Tokyo?",
    )
    print(result.output)


if __name__ == "__main__":
    main()
