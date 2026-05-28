# Array Declaration
arr1 = Array(Int32).new
arr2 = [] of Int32
arr3 = [1, 2, 3, 4, 5]
arr4 = %w(a b c d e f g)

# Accessing Array Elements
p! arr3[0]
p! arr4[1]

# Array Length
p! arr3.size

# Adding Elements
arr3 << 6
p! arr3

# Removing Elements
arr3.delete_at(0)
p! arr3

# Iterating Over Array
arr3.each do |element|
  print "#{element} "
end

puts

# Array Slicing
p! arr4[0..2]
p! arr4[2..]
p! arr4[..2]

# Array Concatenation
arr5 = arr3 + arr4
p! arr5

# Array Sorting
arr6 = [5, 3, 4, 1, 2]
p! arr6.sort

# Array Reversing
p! arr6.reverse
