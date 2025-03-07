from agno.agent.agent import Agent
from dotenv import load_dotenv

from ai_demos.agno_examples.utils import configure_and_get_openai_client

load_dotenv()


def get_weather(city: str) -> str:
    """
    Get the weather for a given city.
    Args:
        city (str): The name of the city to get the weather for.
    Returns:
        str: The current weather in the specified city.
    """
    import random

    weathers = "rainy sunny cloudy stormy snowy windy".split(" ")
    return random.choice(weathers)


agent = Agent(
    tools=[get_weather],
    model=configure_and_get_openai_client(),
    instructions="You are a helpful assistant.",
    show_tool_calls=True,
    markdown=True,
    monitoring=True,
)

if __name__ == "__main__":
    agent.print_response("What is the weather in New York?")
