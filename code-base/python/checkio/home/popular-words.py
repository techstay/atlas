import re


def popular_words(text: str, words: list) -> dict:
    text_words = re.findall(r"[a-z']+", text.lower())
    word_counts = dict.fromkeys(words, 0)

    for word in text_words:
        if word in word_counts:
            word_counts[word] += 1

    return word_counts


print("Example:")
print(
    popular_words(
        """
When I was One
I had just begun
When I was Two
I was nearly new
""",
        ["i", "was", "three", "near"],
    )
)

assert popular_words(
    "\nWhen I was One\nI had just begun\nWhen I was Two\nI was nearly new\n",
    ["i", "was", "three", "near"],
) == {"i": 4, "was": 3, "three": 0, "near": 0}

print("The mission is done! Click 'Check Solution' to earn rewards!")
