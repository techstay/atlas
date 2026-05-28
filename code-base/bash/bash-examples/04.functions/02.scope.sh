#!/usr/bin/env bash

# Variables are global by default in Bash.
name="techstay"

hello() {
  # local limits the variable to this function.
  local name="Jackson"
  echo $name
}

echo "$name"

hello
