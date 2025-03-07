from pydantic import BaseModel
from pydantic_ai import Agent

from ai_demos.pydantic_ai_examples.utils import configure_and_get_pydantic_ai_provider


class CityInfo(BaseModel):
    city: str
    country: str


agent = Agent(
    configure_and_get_pydantic_ai_provider(),
    output_type=CityInfo,
)


def main():
    result = agent.run_sync(
        "Where were the first modern Olympic Games held?",
    )
    print(result.output)


if __name__ == "__main__":
    main()
