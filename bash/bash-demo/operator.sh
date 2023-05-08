#!/bin/bash

# checking if the operand is a directory
[ -d '/usr/bin' ] && echo "it's a directory" || echo "it's not a directory"

# checking the given file or directory exists
[ -e '/usr/bin' ] && echo "file or directory exists" || echo "file or directory doesn't exist"

# number comparison
[ 20 -ge 20 ] && echo "20 is greater than or equal to 20" || echo "20 is less than 20"
[ 20 -le 20 ] && echo "20 is less than or equal to 20" || echo "20 is greater than 20"
[ 20 -eq 20 ] && echo "20 is equal to 20" || echo "20 is not equal to 20"
[ 20 -ne 20 ] && echo "20 is not equal to 20" || echo "20 is equal to 20"
[ 20 -gt 20 ] && echo "20 is greater than 20" || echo "20 is less than or equal to 20"
[ 20 -lt 20 ] && echo "20 is less than 20" || echo "20 is greater than or equal to 20"
