# frozen_string_literal: true
# typed: true

# accessing string elements

# finding elements, the element is returned if matched, otherwise nil is returned
my_string = 'Welcome to Ruby world!'
p my_string['Ruby']
p my_string['Python']

# getting single character
p my_string[0].chr

# getting index of elements
p my_string.index('Ruby')

# accessing using ranges
p my_string[0..6]
p my_string[0, 7]
