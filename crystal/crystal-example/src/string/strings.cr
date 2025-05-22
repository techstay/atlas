single_line_string = "This is a single line string"

multi_line_string = <<-STRING
This is a multi-line string
It can span multiple lines
And include special characters like \n and \t.
STRING

puts single_line_string
puts multi_line_string

# Percent String

percent_string = %[This is a "percent string"]

puts percent_string

# String Interpolation

name = "John"
age = 30

puts "Name: #{name}, Age: #{age}"
puts %q(Name: #{name}, Age: #{age}) # no interpolation or escaping
