#!/usr/bin/env bash

# Define a function and read its positional parameters.
hello() {
  # $1, $2, ...  - positional parameters
  # $*           - all parameters as one word when quoted
  # $@           - all parameters as separate words when quoted
  # $#           - number of parameters
  # $?           - exit status of the previous command
  # $!           - PID of the most recent background command
  # $_           - last argument of the previous command
  echo "All args via \$*: $*"
  echo "First arg: $1"
  echo "Second arg: $2"
}

hello "techstay" "jackson"

# Demonstrate the key difference between "$*" and "$@".
demo_diff() {
  echo '--- "$*" (single string, loops only once) ---'
  # shellcheck disable=SC2066  # Intentional: "$*" expands to one word.
  for arg in "$*"; do
    echo "  arg: $arg"
  done

  echo "--- \"\$@\" (separate args) ---"
  for arg in "$@"; do
    echo "  arg: $arg"
  done
}

demo_diff "hello world" "foo bar"
