#!/usr/bin/env bash

# Test whether the path is a directory.
[[ -d '/usr/bin' ]] && echo "it's a directory" || echo "it's not a directory"

# Test whether the path exists as any file type.
[[ -e '/usr/bin' ]] && echo "file or directory exists" || echo "file or directory doesn't exist"

# Numeric comparisons inside [[...]].
a=20
b=20
[[ $a -ge $b ]] && echo "$a >= $b" || echo "$a < $b"
[[ $a -le $b ]] && echo "$a <= $b" || echo "$a > $b"
[[ $a -eq $b ]] && echo "$a == $b" || echo "$a != $b"
[[ $a -ne $b ]] && echo "$a != $b" || echo "$a == $b"
[[ $a -gt $b ]] && echo "$a > $b" || echo "$a <= $b"
[[ $a -lt $b ]] && echo "$a < $b" || echo "$a >= $b"

# String comparisons and empty-string checks.
str1="abc"
str2="abc"
[[ $str1 == "$str2" ]] && echo "strings match" || echo "strings don't match"
[[ -z "$str1" ]] && echo "str1 is empty" || echo "str1 is not empty"
[[ -n "$str2" ]] && echo "str2 is not empty" || echo "str2 is empty"
