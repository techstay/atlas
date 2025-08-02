import os

# from phoenix.otel import register
from smolagents import HfApiModel, OpenAIServerModel

from ai_demos.utils import OpenAIClientConfig
from ai_demos.utils import bigmodel_config as model_config

# https://app.phoenix.arize.com/management/spaces
os.environ["PHOENIX_CLIENT_HEADERS"] = f"api_key={os.getenv('PHOENIX_API_KEY')}"
os.environ["PHOENIX_COLLECTOR_ENDPOINT"] = "https://app.phoenix.arize.com/s/techstay"

# tracer_provider = register(
#     project_name="default",  # Default is 'default'
#     auto_instrument=True,  # Auto-instrument your app based on installed OI dependencies
#     protocol="http/protobuf"
# )


def get_custom_model(
    config: OpenAIClientConfig = model_config,
):
    return OpenAIServerModel(
        model_id=config.model,
        api_key=config.api_key,
        api_base=config.base_url,
    )


qwq_32b_model = HfApiModel(
    "Qwen/QwQ-32B",
    token=os.getenv("HUGGINGFACEHUB_API_TOKEN"),
)
