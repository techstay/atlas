#!/usr/bin/env bash

# Parentheses run commands in a subshell.
(cd /tmp && pwd)
echo "Still in: $(pwd)"

# Variable changes inside a subshell do not affect the parent shell.
x=10
# shellcheck disable=SC2030,SC2031  # Intentional: demonstrates subshell isolation.
(x=20; echo "Inside subshell: $x")
# shellcheck disable=SC2031  # Intentional: shows x unchanged after the subshell.
echo "Outside subshell: $x"

# Braces group commands in the current shell.
{
  y=30
  echo "Inside block: $y"
}
echo "Outside block: $y"

# Use a subshell to group commands in a pipeline.
# shellcheck disable=SC2012,SC2162  # Intentional: simple demo, not production code.
ls | (read first; echo "First file: $first")
