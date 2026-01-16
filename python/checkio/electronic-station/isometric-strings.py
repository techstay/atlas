def isometric_strings(a: str, b: str) -> bool:
    # TODO:
    return len(set(zip(a, b))) == len(set(a))


print("Example:")
print(isometric_strings("add", "egg"))

# These "asserts" are used for self-checking
assert isometric_strings("add", "egg") == True
assert isometric_strings("foo", "bar") == False
assert isometric_strings("bar", "foo") == True
assert isometric_strings("", "") == True
assert isometric_strings("all", "all") == True
assert isometric_strings("gogopy", "doodle") == False
assert isometric_strings("abba", "cccc") == True

print("The mission is done! Click 'Check Solution' to earn rewards!")
