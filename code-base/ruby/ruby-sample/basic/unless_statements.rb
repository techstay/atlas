# frozen_string_literal: true
# typed: true

# unless statements

value = 100
unless value > 100
  puts "value #{value} <= 100"
  # Prevent rubocop reformatting
end

# unless modifiers
puts "value #{value} <= 100" unless value > 600
