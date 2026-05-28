#!/usr/bin/env bash

# Enable strict mode: exit on errors, unset variables, and failed pipelines.
set -euo pipefail

# Store script metadata in readonly variables.
SCRIPT_NAME="$(basename "$0")"
readonly SCRIPT_NAME

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
readonly SCRIPT_DIR

# Write informational messages to standard output.
log_info() {
  echo "[INFO] $*"
}

# Write errors and warnings to standard error.
log_error() {
  echo "[ERROR] $*" >&2
}

log_warn() {
  echo "[WARN] $*" >&2
}

# Register cleanup work to run on exit.
cleanup() {
  log_info "Cleaning up..."
}
trap cleanup EXIT

# Keep script logic in main, then pass through all CLI arguments.
main() {
  log_info "Script started (dir: $SCRIPT_DIR)"

  if [[ $# -eq 0 ]]; then
    log_error "Usage: $SCRIPT_NAME <argument>"
    exit 1
  fi

  log_info "Processing: $1"
}

main "$@"
