import asyncio

from agents import (
    Agent,
    GuardrailFunctionOutput,
    RunContextWrapper,
    Runner,
    input_guardrail,
)
from pydantic import BaseModel

from ai_demos.openai_examples.utils import configure_and_get_custom_model


class FunnyTopic(BaseModel):
    is_funny: bool
    reason: str


guardrail_agent = Agent(
    name="guardrail",
    model=configure_and_get_custom_model(),
    instructions="你是一个守护者，判断话题是否是有趣的",
    output_type=FunnyTopic,
)


@input_guardrail
async def funny_topic_guardrail(
    ctx: RunContextWrapper, agent: Agent, data
) -> GuardrailFunctionOutput:
    result = await Runner.run(
        guardrail_agent,
        input=data,
        context=ctx.context,
    )
    final_output = result.final_output_as(FunnyTopic)
    return GuardrailFunctionOutput(
        output_info=final_output,
        tripwire_triggered=not final_output.is_funny,
    )


joke_agent = Agent(
    "joke",
    model=configure_and_get_custom_model(),
    instructions="你是一个笑话大师,擅长讲笑话",
)

nerd_agent = Agent(
    "nerd",
    model=configure_and_get_custom_model(),
    instructions="你是一个学霸,擅长回答各种问题",
)

adviser_agent = Agent(
    "adviser",
    model=configure_and_get_custom_model(),
    instructions="你来根据问题决定应该使用哪个agent来回答",
    handoffs=[joke_agent, nerd_agent],
    input_guardrails=[
        funny_topic_guardrail,
    ],
)


async def main():
    try:
        result = await Runner.run(
            adviser_agent,
            input="我想听个笑话",
        )
        print(result.final_output)

        result = await Runner.run(
            adviser_agent,
            input="怎么才能学好数学",
        )
        print(result.final_output)
    except Exception as e:
        print(e)


if __name__ == "__main__":
    asyncio.run(main())
