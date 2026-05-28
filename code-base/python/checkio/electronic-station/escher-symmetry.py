def is_figure(data: list[int]) -> bool:
    # TODO:
    if not data:
        return True
    target = data[0] + data[-1]
    return all(a + b == target for a, b in zip(data, data[::-1]))


print("Example:")
print(is_figure([1, 2, 1, 2]))

# These "asserts" are used for self-checking
assert is_figure([1, 2, 1, 2]) == True
assert is_figure([1, 3, 2, 1, 3]) == True
assert is_figure([1, 2, 2, 1]) == False
assert is_figure([4, 4, 4, 4, 4, 4, 4, 4, 4]) == True

print("The mission is done! Click 'Check Solution' to earn rewards!")
