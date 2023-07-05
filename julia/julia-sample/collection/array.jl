##

# creating arrays and matrixes
a1 = [1, 2, 3, 4]
a2 = Array([1, 2, 3])
a3 = Array{Integer,1}([1, 2, 3])
a4 = Array{Number,2}(undef, 2, 2)
a5 = zeros(Int, 5)
a6 = ones(Int, 4, 4)
a7 = trues(2, 2)
a8 = falses(3, 2)
a9 = fill(8, 3, 3)

##
size(a1)
size(a4)

ndims(a1)
ndims(a4)

axes(a1)
axes(a4)

##

a1 = [1:2, 3:4]
# concatenating vertically
a2 = [1:2; 3:4]
# concatenating horizontally
a3 = [1:2 3:4]

##

# comprehensions
a = [x for x = 1:5]
b = [(x, 2x) for x = 1:5]
c = [(y, x) for x = 1:3 for y = 1:x]
d = [(x, y) for x = 1:10 for y = 1:10 if x + y == 10]
# generators
(i for i = 1:5)
sum(i for i ∈ 1:100)

##

# indexing
a1 = collect(1:10)
a2 = reshape(collect(1:9), (3, 3))

# julia array indexes start with 1 not 0
a1[1]
a1[2]

# Cartesian indexing
# element at row 2 column 3
a2[2, 3]

# linear indexing
a2[7]

# linear indexing to Cartesian indexing
CartesianIndices(a2)[7]

a1[3:5]
a2[2, 2]
a2[2, 3]
a2[[2, 2]]

a1 = reshape(1:16, 4, 4)
mask = map(ispow2, a1)
a1[mask]

