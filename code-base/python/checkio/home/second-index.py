def second_index(text: str, symbol: str) -> int | None:
    try:
        return text.index(symbol, text.index(symbol) + 1)
    except ValueError:
        return None


print("Example:")
print(second_index("sims", "s"))

# These "asserts" are used for self-checking
assert second_index("sims", "s") == 3
assert second_index("find the river", "e") == 12
assert second_index("hi", " ") == None
assert second_index("hi mayor", " ") == None
assert second_index("hi mr Mayor", " ") == 5

print("The mission is done! Click 'Check Solution' to earn rewards!")
