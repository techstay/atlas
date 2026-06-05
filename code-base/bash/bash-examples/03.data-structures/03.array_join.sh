#!/usr/bin/env bash

numbers=(1 2 3 4)

# "${array[*]}" joins all elements into a single string.
echo "${numbers[*]}"

# The first character of IFS becomes the join delimiter.
IFS=','
echo "${numbers[*]}"
