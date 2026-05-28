#!/usr/bin/env bash

choice='y'

# Choose between two branches with if and else.
if [[ $choice = 'y' ]]; then
  echo "You choose yes"
else
  echo "You typed no"
fi

choice='q'

# Chain multiple conditions with elif.
if [[ $choice = o ]]; then
  echo "ok"
elif [[ $choice = a ]]; then
  echo "all"
elif [[ $choice = q ]]; then
  echo "quit"
fi
