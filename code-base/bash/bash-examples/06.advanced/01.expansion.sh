#!/usr/bin/env bash

# Tilde expansion resolves ~ to the current user's home directory.
ls ~

# Variable expansion substitutes the variable value.
name="techstay"
echo "Hello $name"

# Command substitution replaces $(...) with command output.
echo "Hello $(whoami)"

# Single quotes suppress all shell expansion.
# shellcheck disable=SC2016  # Intentional: demonstrates single-quote suppression.
echo 'Hello $(whoami)'

# Parameter expansion can inspect and transform variable values.
echo "Hello ${#name}"      # String length
echo "Hello ${name:0:4}"   # Substring
echo "Hello ${name##tech}" # Remove the longest matching prefix
echo "Hello ${name%%stay}" # Remove the longest matching suffix
