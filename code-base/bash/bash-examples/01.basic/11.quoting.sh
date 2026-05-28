#!/usr/bin/env bash

# Single quotes keep everything literal.
name='World'
# shellcheck disable=SC2016  # Intentional: demonstrates literal single quotes.
echo 'Hello $name'

# Double quotes allow variable expansion while preserving spaces.
echo "Hello $name"

# Backslash can escape special characters inside double quotes.
echo "Hello \"World\""

# In single quotes, backslash is literal and cannot escape another single quote.
# Use ANSI-C quoting when escaped characters are needed.
echo $'Hello \'World\''

# ANSI-C quoting supports C-style escape sequences.
echo $'Hello\nWorld'
echo $'Tab:\there'

# Command substitution runs inside double quotes, but not inside single quotes.
echo "Today is $(date)"
# shellcheck disable=SC2016  # Intentional: single quotes suppress expansion.
echo 'Today is $(date)'
