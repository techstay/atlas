import os

from openinference.instrumentation.smolagents import SmolagentsInstrumentor
from phoenix.otel import register
from smolagents import HfApiModel, OpenAIServerModel

from ai_demos.utils import OpenAIClientConfig
from ai_demos.utils import ark_config_mini as ai_config


def configure_and_get_custom_model(
    config: OpenAIClientConfig = ai_config,
) -> OpenAIServerModel | HfApiModel:
    # Setting up the trace
    # visit http://localhost:6006
    register()
    SmolagentsInstrumentor().instrument()

    return OpenAIServerModel(
        model_id=config.model,
        api_key=config.api_key,
        api_base=config.base_url,
    )


qwq_32b_model = HfApiModel(
    "Qwen/QwQ-32B",
    token=os.getenv("HUGGINGFACEHUB_API_TOKEN"),
)
