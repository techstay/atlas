# frozen_string_literal: true
# typed: true

# capitalizing strings
p 'abcd'.capitalize

# capitalizing long texts using iterating
'ab bb bc cd'.split(/ /).each { |word| p word.capitalize }

# upcase
p 'fire in the whole!'.upcase

# downcase
p 'HELLO World'.downcase

# swapcase
p 'iOS'.swapcase
