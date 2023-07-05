# dot vectorization

f(x) = x * 2

f.([1, 2, 3, 4])

# equivalent to broadcasting
broadcast(f, [1, 2, 3, 4])

# @. macro will convert the following function calls to vectorization versions
g(x) = x - 4
h(x) = x * 3
@. f(g(h([1, 2, 3, 4])))
