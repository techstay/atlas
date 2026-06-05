#!/usr/bin/env bash

# Keep script logic in a main function and pass through all CLI arguments.
# This avoids issues with global variable scope and makes testing easier.

SCRIPT_NAME="$(basename "$0")"

main() {
  echo "Script started"

  if [[ $# -eq 0 ]]; then
    echo "[ERROR] Usage: $SCRIPT_NAME <argument>" >&2
    exit 1
  fi

  echo "Processing: $1"
}

# Pass all arguments to main.
main "$@"
