# frozen_string_literal: true
# typed: true

# While statements

i = 0
while i < 5
  print i
  i += 1
end

puts

# Do while statements
i = 0
begin
  print i
  i += 1
end while i < 5

puts

# Use loop with break rather than while
i = 0
loop do
  print i
  i += 1
  break unless i < 5
end

puts
