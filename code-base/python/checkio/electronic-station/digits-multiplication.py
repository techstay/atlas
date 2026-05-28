def checkio(number: int) -> int:
    product = 1
    while number > 0:
        if number % 10 != 0:
            product *= number % 10
        number //= 10
    return product


print("Example:")
print(checkio(123405))

# These "asserts" are used for self-checking
assert checkio(123405) == 120
assert checkio(999) == 729
assert checkio(1000) == 1
assert checkio(1111) == 1

print("The mission is done! Click 'Check Solution' to earn rewards!")
