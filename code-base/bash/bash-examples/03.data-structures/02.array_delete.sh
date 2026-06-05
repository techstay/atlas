#!/usr/bin/env bash

numbers=(1 2 3 4)

# Remove a single element by its index.
unset "numbers[2]"
echo "${numbers[@]}"
