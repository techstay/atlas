import asyncio

from agents import Agent, Runner
from openai.types.responses import ResponseTextDeltaEvent

from ai_demos.openai_examples.utils import configure_and_get_custom_model

agent = Agent(
    name="agent",
    instructions="You are a helpful assistant.",
    model=configure_and_get_custom_model(),
)


async def main():
    result = Runner.run_streamed(agent, input="讲一个苏联笑话")
    async for event in result.stream_events():
        if event.type == "raw_response_event" and isinstance(
            event.data, ResponseTextDeltaEvent
        ):
            print(event.data.delta, end="", flush=True)


if __name__ == "__main__":
    asyncio.run(main())
