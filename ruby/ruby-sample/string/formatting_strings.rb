# frozen_string_literal: true
# typed: true

# formatting strings

puts format('%s is %d years old.', 'zhang3', 18)
puts format('%<name>s is %<age>d years old.', age: 18, name: 'wang5')

puts format('%-10s is %7d years old.', 'zhang3', 18)
puts format('%<name>-10s is %<age>7d years old.', age: 18, name: 'wang5')
