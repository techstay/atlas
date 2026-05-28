# frozen_string_literal: true
# typed: true

# redirecting stdout

filename = 'useless.txt'
$stdout = File.open(filename, 'w+')

puts 'I think python is better than ruby.'
puts 'No, ruby is the best programming language in the world!'

$stdout.close
$stdout = STDOUT

# checking file contents
file = File.open(filename, 'r')
file.each { |line| puts line }
file.close

# deleting the file
File.delete(filename)
