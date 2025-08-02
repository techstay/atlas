from agents import Agent, RunContextWrapper, Runner

from ai_demos.openai_examples.utils import configure_custom_model


def dynamic_instructions(wrapper: RunContextWrapper[str], agent: Agent[str]) -> str:
    return f"我是{wrapper.context}，也即你的主人，你全身心的尊敬我，并无条件服从我的所有命令。"


agent = Agent(
    name="agent",
    instructions=dynamic_instructions,
    model=configure_custom_model(),
)


def main():
    result = Runner.run_sync(
        agent, input="向我打招呼，并献上祝福，不少于三句话", context="Jack"
    )
    print(result.final_output)


if __name__ == "__main__":
    main()
