#!/usr/bin/env bash

# file descriptors
# fd1 is standard output
# fd2 is standard error

# make fd2 follow fd1
echo 666 >results.txt 2>&1

# equivalent way but simpler
echo 666 &>result.txt
