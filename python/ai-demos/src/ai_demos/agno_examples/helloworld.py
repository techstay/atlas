from agno.agent.agent import Agent

from ai_demos.agno_examples.utils import configure_openai_client

# Setting up AGNO_API_KEY and AGNO_MONITOR to true to enable monitoring
# See https://app.agno.com/sessions
agent = Agent(
    model=configure_openai_client(),
    description="You are a helpful assistant and answer questions briefly.",
    markdown=True,
)


if __name__ == "__main__":
    agent.print_response(
        "What text is often used for printing in the quick start of a programming language? "
        "Just tell me the answer."
    )
