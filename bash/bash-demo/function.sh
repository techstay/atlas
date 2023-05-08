#!/usr/bin/env bash

# function
hello() {
  # $1 $2 and $n stand for the nth parameter
  # $* combines all parameters into a string
  # $@ combine all parameters into a list
  # $# parameter counts
  # $? return code of last command
  # $! pid of last command
  # $_ the last parameters of the previous command
  echo "Hello $*"
}

hello "techstay" "zhang3"
