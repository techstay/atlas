def is_all_upper(text: str) -> bool:
    if not any(char.isalpha() for char in text):
        return False
    else:
        return all(char.isupper() for char in text if char.isalpha())


print("Example:")
print(is_all_upper("ALL UPPER"))

# These "asserts" are used for self-checking
assert is_all_upper("ALL UPPER") == True
assert is_all_upper("all lower") == False
assert is_all_upper("mixed UPPER and lower") == False
assert is_all_upper("") == False

print("The mission is done! Click 'Check Solution' to earn rewards!")
