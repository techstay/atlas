import logfire
from openai import AsyncOpenAI
from pydantic_ai import Agent
from pydantic_ai.models.openai import OpenAIModel
from pydantic_ai.providers.openai import OpenAIProvider

from ai_demos.utils import OpenAIClientConfig
from ai_demos.utils import moonshot_config as model_config


def get_pydantic_ai_provider(
    config: OpenAIClientConfig = model_config,
) -> OpenAIModel:
    logfire.configure()
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
