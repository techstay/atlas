##
d = Dict(1 => 1, 2 => 2)

haskey(d, 1)
haskey(d, 3)

get(d, 1, 100)
get(d, 3, 0)

keys(d)
values(d)
pairs(d)

##
delete!(d, 1)
pop!(d, 2)
