foo = () -> (6, 4)

# destructuring assignment
a, b = foo()

# swapping variables
a, b = b, a

# rest destructuring
a, b... = [1, 2, 3, 4, 5]

# property destructuring
(; a, b) = (a=1, b=2, c=3)
(a, b)
