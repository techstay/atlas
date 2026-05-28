import os

from pydantic_ai import Agent
from pydantic_ai.common_tools.duckduckgo import duckduckgo_search_tool
from pydantic_ai.common_tools.tavily import tavily_search_tool

from ai_demos.pydantic_ai_examples.utils import get_pydantic_ai_provider

if __name__ == "__main__":
    agent = Agent(
        get_pydantic_ai_provider(),
        tools=[
            tavily_search_tool(api_key=os.getenv("TAVILY_API_KEY", "")),
            duckduckgo_search_tool(),
        ],
        system_prompt="You are a helpful assistant and you should answer questions concisely and briefly.",
    )

    result = agent.run_sync("哪吒2的最新票房是多少")
    print(result.output)
