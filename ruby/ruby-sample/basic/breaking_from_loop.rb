# frozen_string_literal: true
# typed: true

# break
(1..10).each do |i|
  break if i == 5

  print i
end
puts

# next
(1..10).each do |i|
  next if i == 5

  print i
end
puts

# redo
j = 0
(1..10).each do |i|
  break if j == 3

  redo if i == 5 && j += 1
  print i
end
puts
