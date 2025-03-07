from agno.agent.agent import Agent

from ai_demos.agno_examples.utils import configure_and_get_openai_client

agent = Agent(
    model=configure_and_get_openai_client(),
    description="You are a helpful assistant and answer questions briefly.",
    markdown=True,
)


if __name__ == "__main__":
    agent.print_response(
        "What text is often used for printing in the quick start of a programming language? "
        "Just tell me the answer."
    )
