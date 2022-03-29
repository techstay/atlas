# frozen_string_literal: true
# typed: true

# sorting arrays

numbers = [1, 1, 4, 5, 1, 4]

# returning sorted copies
p numbers.sort
p numbers.reverse
# original arrays are unchanged
p "original: #{numbers}"

# sort the original array not returning sorted copies
numbers.sort!
p numbers

# shuffle arrays
p numbers.shuffle
