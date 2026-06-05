#!/usr/bin/env bash

# Test whether the path is a directory.
[[ -d '/usr/bin' ]] && echo "/usr/bin is a directory" || echo "/usr/bin is not a directory"

# Test whether the path exists as any file type.
[[ -e '/usr/bin' ]] && echo "/usr/bin exists" || echo "/usr/bin doesn't exist"

# Test whether the path is a regular file.
[[ -f '/etc/hosts' ]] && echo "/etc/hosts is a regular file" || echo "/etc/hosts is not a regular file"

# Test whether the path is readable.
[[ -r '/etc/hosts' ]] && echo "/etc/hosts is readable" || echo "/etc/hosts is not readable"

# Test whether the path is writable.
[[ -w '/etc/hosts' ]] && echo "/etc/hosts is writable" || echo "/etc/hosts is not writable"

# Test whether the path is executable.
[[ -x '/bin/bash' ]] && echo "/bin/bash is executable" || echo "/bin/bash is not executable"