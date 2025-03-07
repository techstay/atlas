from smolagents import CodeAgent, tool

from ai_demos.smolagents_examples.utils import configure_and_get_custom_model

joke_agent = CodeAgent(
    tools=[],
    name="Joke Agent",
    description="A joke agent that tells jokes",
    model=configure_and_get_custom_model(),
)


@tool
def get_current_weather() -> str:
    """Get the current weather
    Returns:
        str: The current weather
    """
    return "raining"


manager_agent = CodeAgent(
    tools=[get_current_weather],
    managed_agents=[joke_agent],
    name="Manager Agent",
    description="A manager agent that manages other agents",
    model=configure_and_get_custom_model(),
)

if __name__ == "__main__":
    manager_agent.run("Tell me a joke about the present weather")
