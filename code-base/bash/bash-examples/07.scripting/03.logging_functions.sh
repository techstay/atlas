#!/usr/bin/env bash

# Logging functions for consistent output formatting.
# Errors and warnings are written to standard error (>&2).

# Write informational messages to standard output.
log_info() {
  echo "[INFO] $*"
}

# Write errors to standard error.
log_error() {
  echo "[ERROR] $*" >&2
}

# Write warnings to standard error.
log_warn() {
  echo "[WARN] $*" >&2
}

# Demonstrate usage.
log_info "This is an informational message"
log_warn "This is a warning message"
log_error "This is an error message"
