# typed: true

# replacing a section of a string

my_string = 'Welcome to Ruby world!'

my_string['Ruby'] = 'Python'
puts my_string

my_string[-1] = '!!!'
puts my_string

my_string[11, 6] = 'Ruby'
puts my_string

# leaving orginal string unchanged
puts my_string.gsub('Ruby', 'Python')
puts my_string

# changing directly the original string
puts my_string.gsub!('Ruby', 'Python')
puts my_string
