#!/usr/bin/env bash

declare -A colors

colors[red]="#ff0000"
colors[green]="#00ff00"
colors[blue]="#0000ff"

# Iterate over keys, then read each value by key.
for key in "${!colors[@]}"; do
  echo "$key -> ${colors[$key]}"
done
