IntOrString = Union{Int,String}

a::IntOrString = 5
b::IntOrString = "abc"
# invalid type annotation
c::IntOrString = 2.0
