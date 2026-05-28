#!/usr/bin/env bash

# Run the loop until the condition becomes true.
i=1
until [[ $i -gt 5 ]]; do
  echo "$i"
  ((i++))
done

# Stop the loop immediately when the condition is met.
for i in {1..10}; do
  [[ $i -eq 5 ]] && break
  echo "$i"
done

# Skip the rest of the current iteration when the condition is met.
for i in {1..5}; do
  [[ $((i % 2)) -eq 0 ]] && continue
  echo "$i"
done
