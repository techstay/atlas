from pydantic_ai import Agent

from ai_demos.pydantic_ai_examples.utils import configure_and_get_pydantic_ai_provider

agent = Agent(
    configure_and_get_pydantic_ai_provider(),
    system_prompt="You are a helpful assistant.",
)


async def main():
    async with agent.run_stream("Tell me 10 famous cities in the world.") as response:
        async for chunk in response.stream_text(delta=True):
            print(chunk, end="")
    print()


if __name__ == "__main__":
    import asyncio

    asyncio.run(main())
