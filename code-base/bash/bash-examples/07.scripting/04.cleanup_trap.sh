#!/usr/bin/env bash

# Register cleanup work to run on exit using trap.
# This ensures resources are released even if the script fails or is interrupted.

cleanup() {
  echo "[INFO] Cleaning up..."
  # Add cleanup logic here: remove temp files, kill background processes, etc.
}

# Trap EXIT to run cleanup on normal exit, error exit, or signal interruption.
trap cleanup EXIT

echo "Script is running..."
echo "When the script exits (normally or abnormally), cleanup() will be called."
