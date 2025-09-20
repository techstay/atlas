OPERATION_NAMES = (
    "conjunction",
    "disjunction",
    "implication",
    "exclusive",
    "equivalence",
)


def boolean(x: bool, y: bool, operation: str) -> bool:
    if operation == "conjunction":
        return x and y
    elif operation == "disjunction":
        return x or y
    elif operation == "implication":
        return not x or y
    elif operation == "exclusive":
        return (x or y) and not (x and y)
    elif operation == "equivalence":
        return x == y
    else:
        raise ValueError(f"Unknown operation: {operation}")


print("Example:")
print(boolean(1, 0, "conjunction"))

assert boolean(0, 0, "conjunction") == 0
assert boolean(0, 1, "conjunction") == 0
assert boolean(1, 0, "conjunction") == 0
assert boolean(1, 1, "conjunction") == 1
assert boolean(0, 0, "disjunction") == 0
assert boolean(0, 1, "disjunction") == 1
assert boolean(1, 0, "disjunction") == 1
assert boolean(1, 1, "disjunction") == 1

print("The mission is done! Click 'Check Solution' to earn rewards!")
