#!/usr/bin/env bash

# Use ((...)) to evaluate an arithmetic expression.
((a = 10 + 5))
echo "$a"

# Use $((...)) when the numeric result is needed as text.
b=$((a * 2))
echo "$b"

# Reuse variables directly inside arithmetic evaluation.
((c = a + b))
echo "$c"

# Increment and decrement variables in place.
((a++))
echo "$a"

((b--))
echo "$b"

# Arithmetic comparisons return success or failure for command chaining.
((a > b)) && echo "a is greater" || echo "b is greater"
