##
isempty([])
isempty([1 2 3])

##
dict1 = Dict(1 => 1, 2 => 2)
empty!(dict1)

##
length(1:10)
length([1, 2, 3, 4])
length([1 2; 3 4])

##
s1 = 1:2:10
3 in s1
4 in s1
5 ∈ s1
4 ∉ s1

##
a = ['b', 'b', 'a', 'd']
b = ['a', 'b']
indexin(a, b)

##
a = [1, 1, 2, 2, 3]
unique(a)

a = [1, -1, 2, -2, 3]
unique!(x -> x^2, a)

##
allunique([1, 2, 3])
allunique([1, 1, 2, 3])
allequal([1, 1])
allequal([1, 2, 3])

##
reduce(+, 1:10)
reduce((acc, e) -> acc + 2e, 1:10)
reduce((acc, e) -> acc + 2e, 1:10, init=0)

##
maximum([1, 2, 3, 4])
minimum(length, ["abc", "ab", "a"])
extrema([1, 2, 3, 4])

##
sum([1, 2, 3, 4])
prod([1, 2, 3, 4])

##
any([true, false])
all([true, false])

##
count(x -> x % 2 == 0, 1:10)
count(())

##
foreach(x -> println(x^2), 1:10)

##
map(x -> x^2, 1:10)
1:10 |> collect |> map(x -> x^2)
##
filter(x -> x % 2 == 0, 1:10)

##
mapreduce(x -> 2x, +, 1:10, init=0)

##
first(1:10)
collect(last(1:10, 3))

##
Base.front((1, 2, 3, 4))
Base.tail((1, 2, 3, 4))

##
replace([1, 1, 1, 1], 1 => 2)
replace([1, 1, 1, 1], 1 => 2, count=2)
