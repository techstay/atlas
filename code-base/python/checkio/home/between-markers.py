def between_markers(text: str, begin: str, end: str) -> str:
    """
    returns substring between two given markers
    """
    # Find the start index
    start = text.find(begin)
    if start == -1:
        start_idx = 0
    else:
        start_idx = start + len(begin)

    # Find the end index
    end_idx = text.find(end, start_idx)
    if end_idx == -1:
        end_idx = len(text)

    # If the end marker comes before the start marker, return empty string
    if (text.find(end) != -1 and text.find(begin) != -1 and text.find(end) < text.find(begin)):
        return ""

    return text[start_idx:end_idx]


print("Example:")
print(between_markers("What is >apple<", ">", "<"))

assert between_markers("What is >apple<", ">", "<") == "apple"
assert (
    between_markers("<head><title>My new site</title></head>", "<title>", "</title>")
    == "My new site"
)
assert between_markers("No[/b] hi", "[b]", "[/b]") == "No"
assert between_markers("No [b]hi", "[b]", "[/b]") == "hi"
assert between_markers("No hi", "[b]", "[/b]") == "No hi"
assert between_markers("No <hi>", ">", "<") == ""

print("The mission is done! Click 'Check Solution' to earn rewards!")
