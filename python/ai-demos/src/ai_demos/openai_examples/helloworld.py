from agents import Agent, Runner

from ai_demos.openai_examples.utils import configure_custom_model

agent = Agent(
    name="hello world",
    model=configure_custom_model(),
    instructions="You should answer questions briefly and concisely.",
)


def helloworld():
    result = Runner.run_sync(
        agent,
        input="What text is often used in the first program of a programming language? "
        "Just tell me the answer, without any additional context or explanation",
    )
    print(result.final_output)


if __name__ == "__main__":
    helloworld()
