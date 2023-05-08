#!/bin/bash

# global variables
name="techstay"

hello() {
  # local variables
  local name="zhang3"
  echo $name
}

echo "$name"

hello
