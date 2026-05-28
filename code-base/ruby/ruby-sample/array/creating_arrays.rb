# frozen_string_literal: true
# typed: true

# creating arrays

arr1 = []
arr2 = Array.new(7)
arr3 = Array.new(3, 'a')
arr4 = Array[1, 2, 3, 4, 5]
arr5 = Array.new(10) { |e| (e + 1)**2 }
arr6 = %w[12 3 4 56 77 8 abc def]

p arr5
p arr6
