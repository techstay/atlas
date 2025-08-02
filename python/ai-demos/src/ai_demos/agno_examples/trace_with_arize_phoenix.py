import os

from agno.agent.agent import Agent
from agno.tools.duckduckgo import DuckDuckGoTools
from phoenix.otel import register

from ai_demos.agno_examples.utils import configure_openai_client

# Set environment variables for Arize Phoenix
os.environ["PHOENIX_CLIENT_HEADERS"] = f"api_key={os.getenv('PHOENIX_API_KEY')}"
os.environ["PHOENIX_COLLECTOR_ENDPOINT"] = "https://app.phoenix.arize.com/s/techstay"

# Configure the Phoenix tracer
tracer_provider = register(
    project_name="ai-demos",  # Default is 'default'
    auto_instrument=True,  # Automatically use the installed OpenInference instrumentation
)

# Check https://app.phoenix.arize.com/management/spaces for the trace
agent = Agent(
    model=configure_openai_client(),
    description="You are a helpful assistant.",
    markdown=True,
    tools=[DuckDuckGoTools()],
    show_tool_calls=True,
)

if __name__ == "__main__":
    agent.print_response("哪吒2的最新票房是多少?")
