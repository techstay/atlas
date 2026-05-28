from typing import Any, Iterable


def split_list(items: list[Any]) -> Iterable[list[Any]]:
    if len(items) % 2 == 0:
        return [items[: len(items) // 2], items[len(items) // 2 :]]
    else:
        return [items[: len(items) // 2 + 1], items[len(items) // 2 + 1 :]]


print("Example:")
print(list(split_list([1, 2, 3, 4, 5, 6])))

assert list(split_list([1, 2, 3, 4, 5, 6])) == [[1, 2, 3], [4, 5, 6]]
assert list(split_list([1, 2, 3])) == [[1, 2], [3]]
assert list(split_list(["banana", "apple", "orange", "cherry", "watermelon"])) == [
    ["banana", "apple", "orange"],
    ["cherry", "watermelon"],
]
assert list(split_list([1])) == [[1], []]
assert list(split_list([])) == [[], []]

print("The mission is done! Click 'Check Solution' to earn rewards!")
