#!/usr/bin/env bash

# Create an indexed array.
numbers=(1 2 3 4)

# Expand all elements.
echo "${numbers[@]}"

# Append a single element to the end of the array.
numbers+=(5)
echo "${numbers[@]}"

# Access a single element by its zero-based index.
echo "${numbers[2]}"
