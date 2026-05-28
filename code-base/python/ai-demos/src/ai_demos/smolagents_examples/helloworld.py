from dotenv import load_dotenv
from smolagents import CodeAgent

from ai_demos.smolagents_examples.utils import get_custom_model

load_dotenv()

agent = CodeAgent(
    tools=[],
    model=get_custom_model(),
)

if __name__ == "__main__":
    result = agent.run(
        "what output is often used in first run of a programming language?"
    )
    print(result)
