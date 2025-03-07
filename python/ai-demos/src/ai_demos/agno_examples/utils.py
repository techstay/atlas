from agno.models.openai.chat import OpenAIChat
from dotenv import load_dotenv

from ai_demos.utils import OpenAIClientConfig
from ai_demos.utils import ark_config_mini as con

load_dotenv()


def configure_and_get_openai_client(config: OpenAIClientConfig = con):
    client = OpenAIChat(
        base_url=config.base_url,
        id=config.model,
        api_key=config.api_key,
    )
    return client
