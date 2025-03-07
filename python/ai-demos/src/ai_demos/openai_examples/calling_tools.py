from agents import Agent, Runner, function_tool

from ai_demos.openai_examples.utils import configure_and_get_custom_model


@function_tool
def get_weather(city: str) -> str:
    """Get the weather in a given city"""
    import random

    weather_choices = ["sunny", "cloudy", "rainy", "windy", "foggy", "stormy", "snowy"]
    return f"{random.choice(weather_choices)}"


agent = Agent(
    name="weather broadcast",
    instructions="You are a weather agent",
    model=configure_and_get_custom_model(),
    tools=[get_weather],
)


def main():
    result = Runner.run_sync(
        agent,
        "What's the weather like in Boston?",
    )
    print(result.final_output)
    result = Runner.run_sync(
        agent,
        "What's the weather like in New York?",
    )
    print(result.final_output)


if __name__ == "__main__":
    main()
