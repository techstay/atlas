#!/usr/bin/env bash

# Numeric comparisons inside [[...]].
a=20
b=20
[[ $a -eq $b ]] && echo "$a == $b" || echo "$a != $b"
[[ $a -ne $b ]] && echo "$a != $b" || echo "$a == $b"
[[ $a -gt $b ]] && echo "$a > $b" || echo "$a <= $b"
[[ $a -lt $b ]] && echo "$a < $b" || echo "$a >= $b"
[[ $a -ge $b ]] && echo "$a >= $b" || echo "$a < $b"
[[ $a -le $b ]] && echo "$a <= $b" || echo "$a > $b"