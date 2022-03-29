# frozen_string_literal: true
# typed: true

# if statements

value = 30
if value > 100
  puts("value #{value} > 100")
  # useless comment
  # preventing rubocop refactor this block to if modifiers
end

# if expression
puts("value #{value} < 50") if value < 50

# if else statement
number = 23
is_odd = number.even?
if is_odd
  puts("number #{number} is odd")
else
  puts("number #{number} is even")
end

# if elif statement
score = 80
if score < 60
  puts('failed')
elsif score < 80
  puts('passed')
elsif score < 100
  puts('good')
elsif score == 100
  puts('perfect')
end

# ternary operator

puts(100.even? ? '100 is even' : '100 is odd')
