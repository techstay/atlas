def sort_by_ext(files: list[str]) -> list[str]:
    # Helper function to extract extension and name
    def get_ext_and_name(filename: str):
        # Split the filename into parts
        parts = filename.split(".")

        # Case 1: Filename starts with '.' but has no extension (like '.config')
        if len(parts) == 2 and parts[0] == "":
            return ("", filename)  # Extension is empty string, name is full filename

        # Case 2: Filename ends with '.' (like 'config.')
        if len(parts) >= 2 and parts[-1] == "":
            return ("", filename)  # Extension is empty string, name is full filename

        # Case 3: Filename has at least one '.' but not at start/end
        if len(parts) > 1:
            # Handle cases like 'str1.str2.str3' or '.str1.str2'
            extension = parts[-1]
            name_parts = parts[:-1]  # All parts except the last one
            name = ".".join(name_parts)  # Reconstruct the name with original dots
            return (extension.lower(), name.lower())

        # Case 4: No extension at all
        return ("", filename.lower())

    # Sort the files using the helper function to create the key
    return sorted(files, key=get_ext_and_name)


print("Example:")
print(sort_by_ext(["1.cad", "1.bat", "1.aa"]))

# These "asserts" are used for self-checking
assert sort_by_ext(["1.cad", "1.bat", "1.aa"]) == ["1.aa", "1.bat", "1.cad"]
assert sort_by_ext(["1.cad", "1.bat", "1.aa", "2.bat"]) == [
    "1.aa",
    "1.bat",
    "2.bat",
    "1.cad",
]
assert sort_by_ext(["1.cad", "1.bat", "1.aa", ".bat"]) == [
    ".bat",
    "1.aa",
    "1.bat",
    "1.cad",
]
assert sort_by_ext(["1.cad", "1.bat", ".aa", ".bat"]) == [
    ".aa",
    ".bat",
    "1.bat",
    "1.cad",
]
assert sort_by_ext(["1.cad", "1.", "1.aa"]) == ["1.", "1.aa", "1.cad"]
assert sort_by_ext(["1.cad", "1.bat", "1.aa", "1.aa.doc"]) == [
    "1.aa",
    "1.bat",
    "1.cad",
    "1.aa.doc",
]
assert sort_by_ext(["1.cad", "1.bat", "1.aa", ".aa.doc"]) == [
    "1.aa",
    "1.bat",
    "1.cad",
    ".aa.doc",
]

print("The mission is done! Click 'Check Solution' to earn rewards!")
