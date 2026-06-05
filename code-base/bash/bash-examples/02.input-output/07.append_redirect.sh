#!/usr/bin/env bash

# Append standard output to a file instead of overwriting.
echo "first line" >>output.txt
echo "second line" >>output.txt
cat output.txt
