#!/usr/bin/env bash

# String comparisons and empty-string checks.
str1="abc"
str2="abc"
str3="def"

# Check equality.
[[ $str1 == "$str2" ]] && echo "str1 equals str2" || echo "str1 != str2"
[[ $str1 != "$str3" ]] && echo "str1 != str3" || echo "str1 equals str3"

# Lexicographic comparison.
[[ $str1 < "$str3" ]] && echo "str1 comes before str3" || echo "str1 does not come before str3"

# Empty and non-empty checks.
[[ -z "$str1" ]] && echo "str1 is empty" || echo "str1 is not empty"
[[ -n "$str2" ]] && echo "str2 is not empty" || echo "str2 is empty"

# Check an actually empty variable.
empty=""
[[ -z "$empty" ]] && echo "empty is empty" || echo "empty is not empty"