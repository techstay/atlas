#!/usr/bin/env bash

# tilde expansion
ls ~/"Desktop/test"

# variable expansion
name="techstay"
echo "Hello $name"

# command substitution
echo "Hello $(whoami)"

# single quotes suppress expansion
echo 'Hello $(whoami)'

# parameter expansion
echo "Hello ${#name}"      # length
echo "Hello ${name:0:4}"   # substring
echo "Hello ${name##tech}" # remove start
echo "Hello ${name%%stay}" # remove end
