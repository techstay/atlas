#!/usr/bin/env bash

# Process substitution exposes command output as a temporary file-like path.
# Compare two command outputs without creating files.
diff <(echo "abc") <(echo "abd")

# Feed generated lines into a loop.
while read -r line; do
  echo "Read: $line"
done < <(echo -e "line1\nline2\nline3")

# Combine multiple generated streams.
paste <(echo -e "a\nb\nc") <(echo -e "1\n2\n3")
