import random

import logfire
import nest_asyncio
from agents import (
    Agent,
    Runner,
    function_tool,
    set_default_openai_api,
    set_default_openai_client,
)
from langfuse import get_client
from openai import AsyncOpenAI

from ai_demos.utils import bigmodel_config as model_config

# Configure logfire
nest_asyncio.apply()
logfire.configure(
    service_name="openai-agents",
    send_to_logfire=False,
)
# This method automatically patches the OpenAI Agents SDK to send logs via OTLP to Langfuse.
logfire.instrument_openai_agents()


# Configure Langfuse: https://us.cloud.langfuse.com/
langfuse = get_client()

if langfuse.auth_check():
    print("Langfuse client is authenticated and ready!")
else:
    print("Authentication failed. Please check your credentials and host.")

client = AsyncOpenAI(
    base_url=model_config.base_url,
    api_key=model_config.api_key,
)
set_default_openai_client(client, use_for_tracing=False)
set_default_openai_api("chat_completions")


@function_tool
def get_weather(city: str) -> str:
    """
    Get the weather for a given city
    Args:
        city: The city to get the weather for
    Returns:
        The weather for the given city
    """
    weathers = "sunny rainy cloudy snowy windy".split(" ")
    return f"{random.choice(weathers)}"


weather_agent = Agent(
    name="weather broadcaster",
    model=model_config.model,
    tools=[get_weather],
)


if __name__ == "__main__":
    result = Runner.run_sync(weather_agent, "What's the weather in New York? ")
    print(result.final_output)
