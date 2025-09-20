def is_acceptable_password(password: str) -> bool:
    cond1 = len(password) > 6
    cond2 = any(char.isdigit() for char in password)
    cond3 = not all(char.isdigit() for char in password)
    cond4 = len(password) > 9
    cond5 = password.lower().find("password") == -1
    cond6 = len(set(password)) >= 3
    return cond1 and (cond4 or (cond2 and cond3)) and cond5 and cond6


print("Example:")
print(is_acceptable_password("short"))

# These "asserts" are used for self-checking
assert is_acceptable_password("short") == False
assert is_acceptable_password("short54") == True
assert is_acceptable_password("muchlonger") == True
assert is_acceptable_password("ashort") == False
assert is_acceptable_password("muchlonger5") == True
assert is_acceptable_password("sh5") == False
assert is_acceptable_password("1234567") == False
assert is_acceptable_password("12345678910") == True
assert is_acceptable_password("password12345") == False
assert is_acceptable_password("PASSWORD12345") == False
assert is_acceptable_password("pass1234word") == True
assert is_acceptable_password("aaaaaa1") == False
assert is_acceptable_password("aaaaaabbbbb") == False
assert is_acceptable_password("aaaaaabb1") == True
assert is_acceptable_password("abc1") == False
assert is_acceptable_password("abbcc12") == True
assert is_acceptable_password("aaaaaaabbaaaaaaaab") == False

print("The mission is done! Click 'Check Solution' to earn rewards!")
