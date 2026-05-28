#!/usr/bin/env bash

# Print each command before it runs, often used for debugging.
set -x

name="techstay"
echo "Hello, $name"

# Stop xtrace output.
set +x

# Exit when a simple command returns a non-zero status.
set -e

echo "This will run"
false # This command fails, so the script exits here.
echo "This will NOT run"

# Run this script to see set -e stop before the final echo.
