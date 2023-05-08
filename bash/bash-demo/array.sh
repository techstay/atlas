#!/usr/bin/env bash

numbers=(1 2 3 4)

echo "${numbers[@]}"

# appending elements
numbers+=(5)

echo "${numbers[@]}"

# obtaining elements, the index starting with 0
echo "${numbers[2]}"

# removing elements

unset "numbers[3]"
echo "${numbers[@]}"

# joining array elements into a single string
echo "${numbers[*]}"
# using another delimiter
IFS=','
echo "${numbers[*]}"

# array length
echo "${#numbers[@]}"
