from pydantic import BaseModel
from pydantic_ai import Agent, RunContext

from ai_demos.pydantic_ai_examples.utils import (
    configure_and_get_pydantic_ai_provider,
)


class WeatherInfo(BaseModel):
    city: str
    weather: str


agent = Agent(
    configure_and_get_pydantic_ai_provider(),
    system_prompt="You are a helpful assistant. If you need to get the weather, please use the `get_weather` tool. ",
    output_type=WeatherInfo,
)


@agent.tool
def get_weather(ctx: RunContext, city: str) -> str:
    """Get the weather in a given city"""
    import random

    weathers = "rainy snowy sunny windy foggy stormy".split(" ")
    return f"It's {random.choice(weathers)} in {city}"


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
