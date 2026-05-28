#!/usr/bin/env bash

# A here document feeds multiple lines to standard input.
cat <<EOL
abcd
bbcd
cdcd
EOL

# A here string feeds one string value to standard input.
cat <<<'abcde.
abc bbc.
cbc ddc.
'
