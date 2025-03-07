from smolagents import CodeAgent

from ai_demos.smolagents_examples.utils import configure_and_get_custom_model

agent = CodeAgent(
    tools=[],
    model=configure_and_get_custom_model(),
    add_base_tools=True,
)

if __name__ == "__main__":
    agent.run("哪吒2的最新票房是多少?结果使用中文回答。")
