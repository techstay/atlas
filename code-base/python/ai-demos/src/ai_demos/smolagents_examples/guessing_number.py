from smolagents import CodeAgent, tool

from ai_demos.smolagents_examples.utils import get_custom_model


@tool
def roll_dice()->int:
    """Roll a dice and return the result."""
    import random

    return random.randint(1, 80)

agent=CodeAgent(
    tools=[roll_dice],
    model=get_custom_model(),
)

instructions="""The user first says a number between 1 and 80. You need to roll a dice using the tool and compare the result with the user's number. If they match, respond with 'Congratulations! You guessed it right!'. Otherwise, say the number and reroll the dice and try again until they match."""

user_input="I guess 6"
if __name__ == "__main__":
    agent.run(f"{instructions}\nUser says: {user_input}")


