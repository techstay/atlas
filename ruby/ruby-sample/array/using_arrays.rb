# frozen_string_literal: true
# typed: true

# array manipulation

array1 = (1..10).to_a
puts("array is empty? #{array1.empty?}")
puts("array size: #{array1.size}")
puts("array element type: #{array1[0].class}")

# access array elements
puts("the first element of array: #{array1[0]}")
puts("the first element of aaray: #{array1.first}")
puts("the last element of array: #{array1.last}")
puts("the last element of array: #{array1[-1]}")

# access array index
puts("index of the element 2: #{array1.index(2)}")
puts("index of the last matching element 2: #{array1.rindex(2)}")

# sub range
puts("first half of the array: #{array1[0..4]}")
puts("last half of the array: #{array1.slice(5..9)}")
