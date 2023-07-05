##
using Base.Iterators
rest([1, 2, 3, 4], 2) |> collect

for i = countfrom(1, 3)
  i > 10 && break
  println(i)
end

##
take(1:3:10, 3) |> collect
takewhile(<=(3), 1:10) |> collect
drop(1:3:10, 1) |> collect
dropwhile(<(7), 1:10) |> collect

##
repeated(1, 4) |> collect

##
for (i, v) = cycle("helloworld") |> enumerate
  print(v)
  i > 20 && break
end
println()

##
collect(reverse([1, 2, 3]))

##
(a, rest) = peel([1, 2, 3, 4])
