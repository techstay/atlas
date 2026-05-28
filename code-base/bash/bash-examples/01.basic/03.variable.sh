#!/usr/bin/env bash

name="techstay"
echo "Hello, $name"

# Mark a variable as readonly after assigning it.
age=18
readonly age
echo "Age: $age"

# Remove a variable from the current shell.
unset name

# After unset, expanding name produces an empty value.
echo "$name"

# Reassigning a readonly variable prints an error and returns a failure status.
# With set -e enabled, that failure exits the script immediately.
age=20
