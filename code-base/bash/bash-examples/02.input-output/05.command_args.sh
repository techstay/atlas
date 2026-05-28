#!/usr/bin/env bash

# Positional parameters expose the script name and command-line arguments.
echo "Script name: $0"
echo "First argument: $1"
echo "Second argument: $2"
echo "All arguments:" "$@"
echo "All arguments as one string: $*"
echo "Argument count: $#"

# The shift discards the current $1 and moves the remaining arguments left.
shift
echo "After shift, first argument: $1"
