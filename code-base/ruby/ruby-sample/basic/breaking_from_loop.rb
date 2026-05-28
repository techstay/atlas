# frozen_string_literal: true
# typed: true

# break
(0...10).each do |i|
  break if i == 5

  print i
end
puts

# next
(0...10).each do |i|
  next if i == 5

  print i
end
puts
