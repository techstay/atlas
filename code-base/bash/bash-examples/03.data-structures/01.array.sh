#!/usr/bin/env bash

numbers=(1 2 3 4)

echo "${numbers[@]}"

# Append an element to the end of the indexed array.
numbers+=(5)

echo "${numbers[@]}"

# Array indexes start at 0.
echo "${numbers[2]}"

# Remove an element by index.
unset "numbers[3]"
echo "${numbers[@]}"

# "${array[*]}" joins elements into one string.
echo "${numbers[*]}"
# The first character of IFS becomes the join delimiter.
IFS=','
echo "${numbers[*]}"

# Count the number of set elements.
echo "${#numbers[@]}"
