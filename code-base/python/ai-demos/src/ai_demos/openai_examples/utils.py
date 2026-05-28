import logfire
from agents import (
    add_trace_processor,
    set_default_openai_api,
    set_default_openai_client,
)
from braintrust import init_logger
from braintrust.wrappers.openai import BraintrustTracingProcessor
from openai import AsyncOpenAI

from ai_demos.utils import OpenAIClientConfig
from ai_demos.utils import bigmodel_config as model_config


def configure_custom_model(config: OpenAIClientConfig = model_config) -> str:
    # Enable braintrust tracing: https://www.braintrust.dev/app/
    add_trace_processor(BraintrustTracingProcessor(init_logger("openai-agent")))

    # Enable logfire instrumentation: https://www.logfire.dev/app/
    logfire.configure()
    logfire.instrument_openai_agents()

    client = AsyncOpenAI(
        base_url=config.base_url,
        api_key=config.api_key,
    )
    set_default_openai_client(client, use_for_tracing=False)
    set_default_openai_api("chat_completions")
    return config.model
