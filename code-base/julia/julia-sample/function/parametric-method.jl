# parametric methods
is_same_type(x::T, y::T) where {T} = true
is_same_type(x, y) = false

println(is_same_type(1, 2))
println(is_same_type(1, 1.0))
