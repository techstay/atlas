# full form
function f(a, b)
  a + b
end

# simple form
g(a, b) = a - b

println(f(6, 4))
println(g(6, 4))

# return nothing
function h()
  return nothing
end

h()

# lambda expressions
x = x -> x * 2
println(map(x, [1, 2, 3]))
