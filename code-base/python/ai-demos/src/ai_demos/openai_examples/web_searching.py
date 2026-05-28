from typing import Any

from agents import Agent, Runner, function_tool
from ddgs import DDGS

from ai_demos.openai_examples.utils import configure_custom_model


@function_tool
def search_internet(query: str) -> list[dict[str, Any]]:
    """Search internet for more information.

    Args:
        query (str): The query to search for
    Returns:
        result (list[dict[str, Any]]): The results of the search
    """
    return DDGS().text(query)


agent = Agent(
    name="web search",
    instructions="You are a helpful assistant.",
    model=configure_custom_model(),
    tools=[search_internet],
)


if __name__ == "__main__":
    result = Runner.run_sync(agent, "哪吒2的最新票房是多少?")
    print(result.final_output)
