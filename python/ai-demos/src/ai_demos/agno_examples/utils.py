from agno.models.openai.chat import OpenAIChat

from ai_demos.utils import OpenAIClientConfig
from ai_demos.utils import bigmodel_config as model_config


def configure_openai_client(config: OpenAIClientConfig = model_config):
    client = OpenAIChat(
        base_url=config.base_url,
        id=config.model,
        api_key=config.api_key,
        # When using custom models rather than openai, you may need to remap the roles
        role_map={
            "user": "user",
            "assistant": "assistant",
            "system": "system",
            "developer": "system",
            "tool": "tool",
        },
    )
    return client
