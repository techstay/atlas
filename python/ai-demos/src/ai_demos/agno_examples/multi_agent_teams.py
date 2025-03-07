from agno.agent.agent import Agent
from agno.team.team import Team
from agno.tools.baidusearch import BaiduSearchTools

from ai_demos.agno_examples.utils import configure_and_get_openai_client

web_agent = Agent(
    name="Web Agent",
    role="Search the web for information",
    model=configure_and_get_openai_client(),
    tools=[BaiduSearchTools()],
    instructions="Always include sources",
    show_tool_calls=True,
    markdown=True,
)

thinking_agent = Agent(
    name="Thinking Agent",
    role="Think and output proper contents",
    model=configure_and_get_openai_client(),
    instructions="Always include sources",
    show_tool_calls=True,
    markdown=True,
)

agent_team = Team(
    model=configure_and_get_openai_client(),
    mode="coordinate",
    members=[web_agent, thinking_agent],
    success_criteria="Return inspected data",
    show_tool_calls=True,
    instructions=["Always include sources"],
    markdown=True,
)


if __name__ == "__main__":
    agent_team.print_response("Give me some data about recently America news.")
