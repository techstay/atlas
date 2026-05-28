from smolagents import CodeAgent, WebSearchTool

from ai_demos.smolagents_examples.utils import get_custom_model

agent = CodeAgent(
    tools=[WebSearchTool()],
    model=get_custom_model(),
    add_base_tools=False,
)

if __name__ == "__main__":
    agent.run(
        "哪吒2的最新票房是多少",
    )
