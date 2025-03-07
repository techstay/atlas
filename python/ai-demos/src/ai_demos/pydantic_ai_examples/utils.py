import logfire
from dotenv import load_dotenv
from openai import AsyncOpenAI
from pydantic_ai import Agent
from pydantic_ai.models.openai import OpenAIModel
from pydantic_ai.providers.openai import OpenAIProvider

from ai_demos.utils import OpenAIClientConfig
from ai_demos.utils import ark_config_mini as con

load_dotenv()
# nest_asyncio.apply()
# LANGFUSE_PUBLIC_KEY = os.getenv("LANGFUSE_PUBLIC_KEY")
# LANGFUSE_SECRET_KEY = os.getenv("LANGFUSE_SECRET_KEY")
# LANGFUSE_HOST = os.getenv("LANGFUSE_HOST")
# LANGFUSE_AUTH = base64.b64encode(
#     f"{LANGFUSE_PUBLIC_KEY}:{LANGFUSE_SECRET_KEY}".encode()
# ).decode()
#
# os.environ["OTEL_EXPORTER_OTLP_ENDPOINT"] = f"{LANGFUSE_HOST}/api/public/otel"
# os.environ["OTEL_EXPORTER_OTLP_HEADERS"] = f"Authorization=Basic {LANGFUSE_AUTH}"


def configure_and_get_pydantic_ai_provider(
    config: OpenAIClientConfig = con,
) -> OpenAIModel:
    # configure langfuse
    logfire.configure(
        #     service_name="langfuse",
        #     send_to_logfire=False,
    )
    logfire.instrument_pydantic_ai()
    Agent.instrument_all()

    client = AsyncOpenAI(
        api_key=config.api_key,
        base_url=config.base_url,
    )

    model = OpenAIModel(
        config.model,
        provider=OpenAIProvider(openai_client=client),
    )
    return model
