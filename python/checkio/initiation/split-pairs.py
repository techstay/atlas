from typing import Iterable


def split_pairs(text: str) -> Iterable[str]:
    if len(text) % 2 != 0:
        text += "_"
    return [text[i : i + 2] for i in range(0, len(text), 2)]


print("Example:")
print(list(split_pairs("abcd")))

assert list(split_pairs("abcd")) == ["ab", "cd"]
assert list(split_pairs("abc")) == ["ab", "c_"]
assert list(split_pairs("abcdf")) == ["ab", "cd", "f_"]
assert list(split_pairs("a")) == ["a_"]
assert list(split_pairs("")) == []

print("The mission is done! Click 'Check Solution' to earn rewards!")
