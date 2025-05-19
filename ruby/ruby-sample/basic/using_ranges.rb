# frozen_string_literal: true
# typed: true

# range methods

numbers = 1..10

puts("min of numbers:#{numbers.min}")
puts("max of numbers:#{numbers.max}")

# check contains
puts("numbers contain 11: #{numbers.include?(11)}")
puts("numbers contains 7: #{numbers == 7}")

puts("numbers less than 5: #{numbers.reject { |n| n >= 5 }}")

numbers.each { |n| print "#{n} " }
puts
