# frozen_string_literal: true
# typed: true

# splitting strings

# converting strings to one-element arrays
my_string = 'abcde'
p my_string.split

# splitting strings into character-separated arrays
p my_string.split(//)

p '1,2,3,4'.split(/,/)

# joining arrays into strings
p %w[1 2 3 4].join(',')
