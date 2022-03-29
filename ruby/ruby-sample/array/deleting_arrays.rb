# frozen_string_literal: true
# typed: true

# deleting array elements

# [1 2 3 4 5]
a = (1..5).to_a
# remove 2 [1 3 4 5]
a.delete(2)
# remove 4 at index 2 [1 3 5]
a.delete_at(2)

p a

a = (1..10).to_a
a.delete_if(&:even?)
# equivalent to
# a.delete_if { |e| e.even? }
p a
