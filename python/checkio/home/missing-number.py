def missing_number(items: list[int]) -> int:
    items = sorted(items)
    d = (items[-1] - items[0]) // len(items)
    for i in range(len(items)):
        if items[i] + d not in items:
            return items[i] + d
    return 0


print("Example:")
print(missing_number([1, 4, 2, 5]))

# These "asserts" are used for self-checking
assert missing_number([1, 4, 2, 5]) == 3
assert missing_number([2, 6, 8]) == 4

print("The mission is done! Click 'Check Solution' to earn rewards!")
