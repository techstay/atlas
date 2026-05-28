import agentops
from agno.agent.agent import Agent
from agno.tools.duckduckgo import DuckDuckGoTools

from ai_demos.agno_examples.utils import configure_openai_client

# Trace url: https://app.agentops.ai/traces
agentops.init()

agent = Agent(
    model=configure_openai_client(),
    description="You are a helpful assistant.",
    markdown=True,
    tools=[DuckDuckGoTools(fixed_max_results=5)],
    show_tool_calls=True,
)

if __name__ == "__main__":
    agent.print_response("哪吒2的最新票房是多少?")
