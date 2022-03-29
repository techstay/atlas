# frozen_string_literal: true
# typed: true

# modifying arrays

# inserting elements
a = ('a'..'e').to_a
a.insert(4, 'z')

# pushing elements
a.push 'bbb'

# changing elements
a[0] = 'x'
a[2..3] = 'g', 'h'

p a
