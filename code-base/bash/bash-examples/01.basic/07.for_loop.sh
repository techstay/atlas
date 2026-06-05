#!/usr/bin/env bash

list=(1 2 3 6 10)

# Iterate over an indexed array.
for i in "${list[@]}"; do
  echo "$i"
done
