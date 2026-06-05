#!/usr/bin/env bash

# Run the loop until the condition becomes true.
i=1
until [[ $i -gt 5 ]]; do
  echo "$i"
  ((i++))
done
