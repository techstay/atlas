def is_acceptable_password(password: str) -> bool:
    cond1 = len(password) > 6
    cond2 = any(char.isdigit() for char in password)
    cond3 = not all(char.isdigit() for char in password)
    cond4 = len(password) > 9
    return cond4 or (cond1 and cond2 and cond3)


print("Example:")
print(is_acceptable_password("short"))

# These "asserts" are used for self-checking
assert is_acceptable_password("short") == False
assert is_acceptable_password("short54") == True
assert is_acceptable_password("muchlonger") == True
assert is_acceptable_password("ashort") == False
assert is_acceptable_password("notshort") == False
assert is_acceptable_password("muchlonger5") == True
assert is_acceptable_password("sh5") == False
assert is_acceptable_password("1234567") == False
assert is_acceptable_password("12345678910") == True

print("The mission is done! Click 'Check Solution' to earn rewards!")
