from smolagents import CodeAgent
from smolagents.tools import tool

from ai_demos.smolagents_examples.utils import configure_and_get_custom_model


@tool
def get_weather(city: str) -> str:
    """
    Get the current weather for a given city

    Args:
        city: The name of the city to get the weather for
    """
    import random

    weathers = "sunny rainy snowy windy cloudy stormy".split(" ")
    return f"The weather in {city} is {random.choice(weathers)}."


agent = CodeAgent(
    tools=[get_weather],
    model=configure_and_get_custom_model(),
    add_base_tools=True,
)


if __name__ == "__main__":
    agent.run("what's the weather in London")
    agent.run("what's the weather of Tokyo?")
