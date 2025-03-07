import os

from pydantic_ai import Agent
from pydantic_ai.common_tools.duckduckgo import duckduckgo_search_tool
from pydantic_ai.common_tools.tavily import tavily_search_tool

from ai_demos.pydantic_ai_examples.utils import configure_and_get_pydantic_ai_provider


def duckduckgo_search():
    agent = Agent(
        configure_and_get_pydantic_ai_provider(),
        tools=[duckduckgo_search_tool()],
        system_prompt="Search duckduckgo for information and answer the question.",
    )

    result = agent.run_sync("哪吒2的最新票房是多少？")
    print(result.output)


def tavily_search():
    agent = Agent(
        configure_and_get_pydantic_ai_provider(),
        tools=[
            tavily_search_tool(api_key=os.getenv("TAVILY_API_KEY", "")),
        ],
        system_prompt="Search Tavily for information and answer the question.",
    )

    result = agent.run_sync("哪吒2的最新票房是多少？")
    print(result.output)


if __name__ == "__main__":
    duckduckgo_search()
    # tavily_search()
