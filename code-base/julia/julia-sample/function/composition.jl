# function composition, the procedure is from right to left
# type \circ<tab> to input the circle symbol
f(x) = x * 2
g(x) = x + 6
h = f ∘ g

println(h(3))
