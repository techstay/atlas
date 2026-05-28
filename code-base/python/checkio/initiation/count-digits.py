def count_digits(text: str) -> int:
    return sum(c.isdigit() for c in text)


print("Example:")
print(count_digits("hi"))

# These "asserts" are used for self-checking
assert count_digits("hi") == 0
assert count_digits("who is 1st here") == 1
assert count_digits("my numbers is 2") == 1
assert (
    count_digits(
        "This picture is an oil on canvas painting by Danish artist Anna Petersen between 1845 and 1910 year"
    )
    == 8
)
assert count_digits("5 plus 6 is") == 2
assert count_digits("") == 0

print("The mission is done! Click 'Check Solution' to earn rewards!")
