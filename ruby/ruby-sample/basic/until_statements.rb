# frozen_string_literal: true
# typed: true

# until statements

i = 0
until i >= 5
  print i
  i += 1
end
puts

# until modifiers
i = 0
begin
  print i
  i += 1
end until i >= 5
puts

# Use loop with break rather than until
i = 0
loop do
  print i
  i += 1
  break if i >= 5
end
puts
