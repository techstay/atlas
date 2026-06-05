#!/usr/bin/env bash

# Stop the loop immediately when the condition is met.
for i in {1..10}; do
  [[ $i -eq 5 ]] && break
  echo "$i"
done
