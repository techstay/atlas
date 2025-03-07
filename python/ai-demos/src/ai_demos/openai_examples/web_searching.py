from agents import Agent, Runner, function_tool
from agno.tools.duckduckgo import DuckDuckGoTools

from ai_demos.openai_examples.utils import configure_and_get_custom_model


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
    model=configure_and_get_custom_model(),
    tools=[search_internet],
)


if __name__ == "__main__":
    result = Runner.run_sync(agent, "哪吒2的最新票房是多少?")
    print(result.final_output)
