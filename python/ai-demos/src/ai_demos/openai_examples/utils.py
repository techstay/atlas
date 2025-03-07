import logfire
from agents import (
    set_default_openai_api,
    set_default_openai_client,
    set_trace_processors,
)
from braintrust import init_logger
from braintrust.wrappers.openai import BraintrustTracingProcessor
from dotenv import load_dotenv
from openai import AsyncOpenAI

from ai_demos.utils import OpenAIClientConfig
from ai_demos.utils import ark_config_mini as con

load_dotenv()


def configure_and_get_custom_model(config: OpenAIClientConfig = con) -> str:
    set_trace_processors([BraintrustTracingProcessor(init_logger("openai-agent"))])

    logfire.configure()
    logfire.instrument_openai_agents()
    client = AsyncOpenAI(
        base_url=config.base_url,
        api_key=config.api_key,
    )
    set_default_openai_client(client, use_for_tracing=False)
    set_default_openai_api("chat_completions")
    return config.model
