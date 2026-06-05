#!/usr/bin/env bash

# Declare an associative array. Requires Bash 4 or newer.
declare -A colors

colors[red]="#ff0000"
colors[green]="#00ff00"
colors[blue]="#0000ff"

# Access a value by key.
echo "${colors[red]}"

# Expand all keys.
echo "${!colors[@]}"

# Expand all values.
echo "${colors[@]}"

# Count the number of key-value pairs.
echo "${#colors[@]}"
