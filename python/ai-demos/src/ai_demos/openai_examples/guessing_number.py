from agents import Agent, Runner, function_tool

from ai_demos.openai_examples.utils import configure_and_get_custom_model


@function_tool
def roll_dice() -> int:
    """Roll a die and get the value between 1-6."""
    import random

    n = random.randint(1, 6)
    # logfire.info(f"Rolling a die, got {n}")
    return n


agent = Agent(
    "guess number",
    "你是一个猜数游戏，用户猜一个数字，然后你调用roll_dice函数来模拟掷骰子，如果结果和用户不一致就继续掷骰子，直到用户猜中为止，然后恭喜用户🎉",
    model=configure_and_get_custom_model(),
    tools=[roll_dice],
)


def main():
    result = Runner.run_sync(agent, input="I guess 4")
    print(result.final_output)


if __name__ == "__main__":
    main()
