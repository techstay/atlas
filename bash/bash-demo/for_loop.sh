#!/bin/bash

list=(1 2 3 6 10)

for i in "${list[@]}"; do
  echo "$i"
done

for i in {1..5}; do
  echo "$i"
done
