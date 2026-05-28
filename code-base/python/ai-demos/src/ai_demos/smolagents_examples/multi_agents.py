import random

from smolagents import CodeAgent, tool

from ai_demos.smolagents_examples.utils import get_custom_model

host_agent = CodeAgent(
    tools=[],
    name="host_agent",
    model=get_custom_model(),
    instructions="Introduce the city in 100 words, and then broadcast the weather.",
)


@tool
def get_current_weather(city: str) -> str:
    """
    Get the current weather for a given city
    Args:
        city (str): The name of the city
    Returns:
        str: The current weather
    """
    weather = random.choice("sunny rainy stormy snowy windy cloudy".split(" "))
    return f"The current weather in {city} is {weather}."


weather_forecast_agent = CodeAgent(
    tools=[get_current_weather],
    name="weather_forecast_agent",
    description="A weather forecast agent that provides weather updates",
    model=get_custom_model(),
)

manager_agent = CodeAgent(
    tools=[get_current_weather],
    managed_agents=[host_agent, weather_forecast_agent],
    name="manager_agent",
    description="A manager agent that manages other agents",
    model=get_custom_model(),
)

if __name__ == "__main__":
    manager_agent.run("Tell me about London")
