#!/usr/bin/env bash

# return sets a function's exit status, not a general data value.
# Exit statuses are limited to 0-255; larger numbers wrap modulo 256.
# Use stdout to pass arbitrary data back to the caller.
add() {
  local result=$(($1 + $2))
  return "$result"
}

add 3 5
echo "Return value: $?"

# Capture function output when you need a data value.
greet() {
  echo "Hello, $1!"
}

message=$(greet "World")
echo "$message"

# Use return for success or failure status.
check_file() {
  [[ -f "$1" ]] && return 0 || return 1
}

check_file "/etc/hosts"
echo "File exists: $?"
