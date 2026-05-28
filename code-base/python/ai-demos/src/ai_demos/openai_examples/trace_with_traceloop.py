import random

from agents import (
    Agent,
    Runner,
    function_tool,
    set_default_openai_api,
    set_default_openai_client,
)
from openai import AsyncOpenAI
from traceloop.sdk import Traceloop
from traceloop.sdk.instruments import Instruments

from ai_demos.utils import bigmodel_config as model_config

# See https://app.traceloop.com/projects/default/trace
Traceloop.init(disable_batch=True, instruments={Instruments.OPENAI})

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
