# frozen_string_literal: true
# typed: true

# formatting strings

puts format('%s is %d years old.', 'jack', 18)
puts format('%<name>s is %<age>d years old.', age: 18, name: 'jackson')

puts format('%<name>-10s is %<age>7d years old.', name: 'david', age: 18)
puts format('%<name>-10s is %<age>7d years old.', age: 18, name: 'michael')

# String interpolation
name = 'Jack'
age = 18
puts "name: #{name}, age: #{age}"
