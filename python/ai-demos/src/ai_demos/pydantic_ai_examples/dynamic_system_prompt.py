from pydantic_ai import Agent, RunContext

from ai_demos.pydantic_ai_examples.utils import (
    get_pydantic_ai_provider,
)

agent = Agent(
    get_pydantic_ai_provider(),
    deps_type=str,
)


@agent.system_prompt
def dynamic_system_prompt(ctx: RunContext[str]) -> str:
    return f"The username is {ctx.deps}"


if __name__ == "__main__":
    result = agent.run_sync(
        "Say hello to the user",
        deps="Jackson",
    )
    print(result.output)
