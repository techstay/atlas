from agno.agent.agent import Agent
from agno.tools.baidusearch import BaiduSearchTools

from ai_demos.agno_examples.utils import configure_and_get_openai_client

agent = Agent(
    model=configure_and_get_openai_client(),
    description="You are a helpful assistant.",
    markdown=True,
    tools=[BaiduSearchTools()],
    show_tool_calls=True,
)

if __name__ == "__main__":
    agent.print_response("哪吒2的最新票房是多少?")
