def changing_direction(elements: list[int]) -> int:
    if len(elements) < 2:
        return 0

    changes = 0
    direction = None

    for i in range(1, len(elements)):
        if elements[i] > elements[i - 1]:
            current_direction = "up"
        elif elements[i] < elements[i - 1]:
            current_direction = "down"
        else:
            continue

        if direction is None:
            direction = current_direction
        elif direction != current_direction:
            changes += 1
            direction = current_direction

    return changes


print("Example:")
print(changing_direction([1, 2, 3, 4, 5]))

# These "asserts" are used for self-checking
assert changing_direction([1, 2, 3, 4, 5]) == 0
assert changing_direction([1, 2, 3, 2, 1]) == 1
assert changing_direction([1, 2, 2, 1, 2, 2]) == 2

print("The mission is done! Click 'Check Solution' to earn rewards!")
