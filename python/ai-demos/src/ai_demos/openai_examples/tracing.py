import random

import logfire

# import agentops
from agents import (
    Agent,
    Runner,
    function_tool,
    set_default_openai_api,
    set_default_openai_client,
    set_trace_processors,
)
from braintrust import init_logger
from braintrust.wrappers.openai import BraintrustTracingProcessor
from dotenv import load_dotenv
from openai import AsyncOpenAI
from phoenix.otel import register

# from scorecard import Tracer
from ai_demos.utils import ark_config_mini as config

load_dotenv()

# scorecard tracing
# tracer = Tracer(api_key=os.getenv("SCORECARD_API_KEY", ""))
# tracer.instrument_agents()

# agentops tracing
# agentops.init(
#     api_key=os.getenv("AGENTOPS_API_KEY"),
#     default_tags=["openai agents sdk"],
# )
set_trace_processors([BraintrustTracingProcessor(init_logger("openai-agent"))])

# phoenix tracing
tracer_provider = register(
    auto_instrument=True,
)

# configure langfuse
# langfuse_public_key = os.getenv("LANGFUSE_PUBLIC_KEY")
# langfuse_secret_key = os.getenv("LANGFUSE_SECRET_KEY")
# langfuse_host = os.getenv("LANGFUSE_HOST")
# if langfuse_host.endswith("/"):
#     langfuse_host = langfuse_host[:-1]
# langfuse_auth = base64.b64encode(
#     f"{langfuse_public_key}:{langfuse_secret_key}".encode()
# ).decode()
# os.environ["OTEL_EXPORTER_OTLP_ENDPOINT"] = f"{langfuse_host}/api/public/otel"
# os.environ["OTEL_EXPORTER_OTLP_HEADERS"] = f"Authorization=Basic {langfuse_auth}"

client = AsyncOpenAI(
    base_url=config.base_url,
    api_key=config.api_key,
)
set_default_openai_client(client, use_for_tracing=False)
set_default_openai_api("chat_completions")

logfire.configure()
logfire.instrument_openai_agents()

helloworld_agent = Agent(
    name="helloworld",
    instructions="You should answer questions briefly and concisely.",
    model=config.model,
)


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
    model=config.model,
    tools=[get_weather],
)


if __name__ == "__main__":

    result = Runner.run_sync(
        helloworld_agent,
        "What's the differences between Japan and Nippon?",
    )
    print(result.final_output)

    result = Runner.run_sync(weather_agent, "What's the weather in New York? ")
    print(result.final_output)
