#!/usr/bin/env bash

name="techstay"
echo "Hello, $name"

# readonly variables
age=18
readonly age
echo $age
age=20

# removing variables
unset name

# now name is removed
echo "$name"
