# frozen_string_literal: true
# typed: true

# output

# print strings (no new line)
print 'abc'

# print string
puts 'def'

# print single character
putc 105
putc 0x67
puts

# print formatted strings
printf($stdout, "%s is %d years old.\n", 'techstay', 18)

# print formatted strings
puts format('%<name>s is %<age>d years old.', name: 'techstay', age: 18)
