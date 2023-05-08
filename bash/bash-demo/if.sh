#!/usr/bin/env bash

choice='y'

if [[ $choice = 'y' ]]; then
  echo "You choose yes"
else
  echo "You typed no"
fi

choice='q'

if [[ $choice = o ]]; then
  echo "ok"
elif [[ $choice = a ]]; then
  echo "all"
elif [[ $choice = q ]]; then
  echo "quit"
fi
