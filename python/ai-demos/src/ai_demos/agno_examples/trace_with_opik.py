import os

from agno.agent import Agent
from agno.tools.duckduckgo import DuckDuckGoTools
from openinference.instrumentation.agno import AgnoInstrumentor
from opentelemetry import trace as trace_api
from opentelemetry.exporter.otlp.proto.http.trace_exporter import OTLPSpanExporter
from opentelemetry.sdk.trace import TracerProvider
from opentelemetry.sdk.trace.export import SimpleSpanProcessor

from ai_demos.agno_examples.utils import configure_openai_client

# Set environment variables for Opik
os.environ["OTEL_EXPORTER_OTLP_HEADERS"] = (
    f"Authorization={os.getenv('OPIK_API_KEY')},Comet-Workspace=default"
)
os.environ["OTEL_EXPORTER_OTLP_ENDPOINT"] = (
    "https://www.comet.com/opik/api/v1/private/otel"
)

# Configure the tracer provider
tracer_provider = TracerProvider()
tracer_provider.add_span_processor(SimpleSpanProcessor(OTLPSpanExporter()))
trace_api.set_tracer_provider(tracer_provider=tracer_provider)

AgnoInstrumentor().instrument()

# Check https://www.comet.com/opik/ for the trace
agent = Agent(
    model=configure_openai_client(),
    description="You are a helpful assistant.",
    markdown=True,
    tools=[DuckDuckGoTools()],
    show_tool_calls=True,
)

if __name__ == "__main__":
    agent.print_response("哪吒2的最新票房是多少?")
