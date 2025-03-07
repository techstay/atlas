import logfire
import rich
from pydantic_ai import Agent

from ai_demos.pydantic_ai_examples.utils import (
    configure_and_get_pydantic_ai_provider,
)

agent = Agent(
    configure_and_get_pydantic_ai_provider(),
    system_prompt=(
        "你是一个骰子游戏，首先用户需要猜测一个数字，然后你使用`play_dice`工具来投掷骰子，然后检查用户猜测的数字是否正确。"
        "如果猜测正确，你需要告诉用户猜测正确，并且游戏结束。如果用户猜测错误，继续调用`play_dice`工具投掷骰子，直到用户猜测正确。"
        "最后祝贺一下用户🎉"
    ),
    output_retries=10,
)


@agent.tool_plain
def play_dice() -> int:
    """Roll a six-sided die and return the result(1-6)."""
    import random

    n = random.randint(1, 6)
    logfire.info(f"Rolled a {n}")
    return n


def guess_number():
    result = agent.run_sync("I guess 6")
    rich.print(result.output)
    print(f"Total tokens: {result.usage().total_tokens}")


if __name__ == "__main__":
    guess_number()
