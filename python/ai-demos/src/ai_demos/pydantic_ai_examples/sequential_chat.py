from pydantic_ai import Agent

from ai_demos.pydantic_ai_examples.utils import (
    get_pydantic_ai_provider,
)


def sequential_chat():
    message_history = []
    agent = Agent(
        get_pydantic_ai_provider(),
        system_prompt="Answer questions briefly in one sentence.",
    )
    result = agent.run_sync("Who is Albert Einstein?")
    print(result.output)

    message_history.extend(result.new_messages())
    result = agent.run_sync(
        "How many Nobel Prize he won?",
        message_history=message_history,
    )
    print(result.output)

    message_history.extend(result.new_messages())
    result = agent.run_sync(
        "Who won Nobel Prize for more than one times? (people, not organizations)",
        message_history=message_history,
    )
    print(result.output)


if __name__ == "__main__":
    sequential_chat()
