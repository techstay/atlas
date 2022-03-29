# frozen_string_literal: true
# typed: true

numbers = (1..10).to_a

# selecting elements
p(numbers.select { |i| i >= 5 })

# collecting elements
p numbers.collect(&:even?)

# mapping elements
p(numbers.map { |i| i**2 })

# using above methods together
p numbers.select { |i| i >= 5 }
         .map { |i| i**2 }
