from pydantic_ai import Agent, RunContext

from ai_demos.pydantic_ai_examples.utils import (
    configure_and_get_pydantic_ai_provider,
)

agent = Agent(
    configure_and_get_pydantic_ai_provider(),
    deps_type=str,
)


@agent.system_prompt
def dynamic_system_prompt(ctx: RunContext[str]) -> str:
    return f"The username is {ctx.deps}"


def main():
    result = agent.run_sync(
        "Say hello to the user",
        deps="Jackson",
    )
    print(result.output)


if __name__ == "__main__":
    main()
