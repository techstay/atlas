def verify_anagrams(a: str, b: str) -> bool:
    # TODO:
    return sorted(a.lower().replace(" ", "")) == sorted(b.lower().replace(" ", ""))


print("Example:")
print(verify_anagrams("Programming", "Gram Ring Mop"))

assert verify_anagrams("Programming", "Gram Ring Mop") == True
assert verify_anagrams("Hello", "Ole Oh") == False
assert verify_anagrams("Kyoto", "Tokyo") == True

print("The mission is done! Click 'Check Solution' to earn rewards!")
