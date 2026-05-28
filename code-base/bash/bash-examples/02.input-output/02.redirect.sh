#!/usr/bin/env bash

# File descriptors:
# 1 is standard output; 2 is standard error.

# Redirect standard output to a file, then send standard error to the same target.
echo 666 >results.txt 2>&1

# Bash shorthand for redirecting both standard output and standard error.
echo 666 &>result.txt
