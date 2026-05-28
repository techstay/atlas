#!/usr/bin/env bash

i=1
while [[ $i -le 5 ]]; do
  echo "$i"
  ((i += 1))
done
