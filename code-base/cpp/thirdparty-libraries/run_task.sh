#!/usr/bin/env bash
set -e

if [ -z "$1" ]; then
    echo "Error: no file path provided" >&2
    exit 1
fi

FILE_PATH="$1"

# Normalize Windows path separators
FILE_PATH="${FILE_PATH//\\//}"

# Validate the file is a .cpp source
if [[ "$FILE_PATH" != *.cpp ]]; then
    echo "Error: $FILE_PATH is not a .cpp file" >&2
    exit 1
fi

# Derive the xmake target name: <subdir>_<basename>
FILE_BASENAME=$(basename "$FILE_PATH" .cpp)
PARENT_DIR_NAME=$(basename "$(dirname "$FILE_PATH")")
TARGET_NAME="${PARENT_DIR_NAME}_${FILE_BASENAME}"

echo "--- Running xmake target: ${TARGET_NAME} ---"
xmake run -y "$TARGET_NAME"
