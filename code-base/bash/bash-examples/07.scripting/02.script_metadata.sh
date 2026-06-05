#!/usr/bin/env bash

# Store script metadata in readonly variables.
# This prevents accidental modification and makes values available throughout the script.

SCRIPT_NAME="$(basename "$0")"
readonly SCRIPT_NAME

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
readonly SCRIPT_DIR

echo "Script name: $SCRIPT_NAME"
echo "Script directory: $SCRIPT_DIR"
