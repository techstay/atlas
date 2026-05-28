#!/usr/bin/env bash

# Run this handler when a command triggers ERR.
trap 'echo "Error on line $LINENO"' ERR

# Run this handler whenever the script exits.
trap 'echo "Script exiting..."' EXIT

# Clean up when the script receives an interrupt or termination signal.
cleanup() {
  echo "Cleaning up..."
  rm -f /tmp/temp_file
}
trap cleanup INT TERM

# Trigger an error so the ERR trap runs.
false

echo "Script continues..."
