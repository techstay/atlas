#!/usr/bin/env bash

# Read a file line by line with while and read.
while read -r line; do
  echo "Read: $line"
done < <(echo -e "apple\nbanana\ncherry")
