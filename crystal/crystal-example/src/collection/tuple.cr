# Tuple Declaration
tuple1 = Tuple(Int32, String, Float64).new(1, "Hello", 3.14)
tuple2 = {1, "Hello", 3.14}

# Accessing Tuple Elements
p! tuple1[0]
p! tuple2[1]

# Tuple Destructuring
a, b, c = tuple1
p! a, b, c

# Tuple Length
p! tuple1.size
