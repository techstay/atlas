#!/usr/bin/env bash

# Enable strict mode:
#   -e  Exit immediately if a command exits with a non-zero status.
#   -u  Treat unset variables as an error and exit.
#   -o pipefail  Return the exit status of the last failed command in a pipeline.
set -euo pipefail

# Demonstrate strict mode behavior.
echo "Strict mode enabled (set -euo pipefail)"

# Example: unset variable would cause an error under -u.
# echo "$UNSET_VAR"  # Uncommenting this line would exit the script.

# Example: failed pipeline would cause an error under -o pipefail.
# false | true  # Uncommenting this line would exit the script.

echo "Script completed successfully."
