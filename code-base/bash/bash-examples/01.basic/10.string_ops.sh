#!/usr/bin/env bash

# Concatenate strings by expanding variables next to literal text.
greeting="Hello"
name="World"
echo "$greeting, $name!"

# Get the number of characters in a string.
echo "${#greeting}"

# Compare strings with [[...]].
s1="abc"
s2="abc"
s3="def"
[[ $s1 == "$s2" ]] && echo "s1 equals s2" || echo "s1 != s2"
[[ $s1 < "$s3" ]] && echo "s1 comes first (lexicographic)" || echo "s3 comes first"

# Extract substrings with offset and optional length.
text="Hello, World!"
echo "${text:0:5}"
echo "${text:7}"

# Replace the first match, or all matches with //.
echo "${text/World/Bash}"
echo "${text//l/L}"

# Remove the shortest matching prefix or suffix pattern.
echo "${text#Hello, }"
echo "${text%World!}"
