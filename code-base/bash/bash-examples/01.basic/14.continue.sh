#!/usr/bin/env bash

# Skip the rest of the current iteration when the condition is met.
for i in {1..5}; do
  [[ $((i % 2)) -eq 0 ]] && continue
  echo "$i"
done
