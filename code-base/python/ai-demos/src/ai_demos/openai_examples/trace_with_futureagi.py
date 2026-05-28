from agents import (
    Agent,
    Runner,
    function_tool,
    set_default_openai_api,
    set_default_openai_client,
)
from agno.tools.duckduckgo import DuckDuckGoTools
from fi_instrumentation import register
from fi_instrumentation.fi_types import ProjectType
from openai import AsyncOpenAI
from traceai_openai_agents import OpenAIAgentsInstrumentor

from ai_demos.utils import bigmodel_config as model_config

# FutureAgi: https://app.futureagi.com/dashboard/observe
trace_provider = register(
    project_type=ProjectType.OBSERVE,
    project_name="openai_project",
)

OpenAIAgentsInstrumentor().instrument(tracer_provider=trace_provider)

client = AsyncOpenAI(
    base_url=model_config.base_url,
    api_key=model_config.api_key,
)

set_default_openai_client(client, use_for_tracing=False)
set_default_openai_api("chat_completions")


@function_tool
def search_internet(query: str) -> str:
    """Search internet for more information.

    Args:
        query (str): The query to search for
    Returns:
        str: The results of the search
    """
    return DuckDuckGoTools().duckduckgo_search(query)


agent = Agent(
    name="web search",
    instructions="你是一个强大的助手，遇到问题可以尝试通过网络搜索获取更多信息。",
    model=model_config.model,
    tools=[search_internet],
)


if __name__ == "__main__":
    result = Runner.run_sync(agent, "哪吒2的最新票房是多少?")
    print(result.final_output)
