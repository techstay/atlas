import logfire
import rich
from pydantic_ai import Agent
from pydantic_ai.models.openai import OpenAIModel
from pydantic_ai.providers.openai import OpenAIProvider

from ai_demos.utils import ollama_config

ollama_model = OpenAIModel(
    model_name=ollama_config.model,
    provider=OpenAIProvider(base_url=ollama_config.base_url),
)

logfire.configure()
logfire.instrument_pydantic_ai()

agent = Agent(
    model=ollama_model,
    system_prompt="You are a helpful assistant. Answer questions briefly.",
)

if __name__ == "__main__":
    result = agent.run_sync(
        "What text is often used in the first demo of a programming language? Just give me the answer."
    )
    print(result.output)
    rich.print(result.usage())
