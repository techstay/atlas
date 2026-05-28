# function piping
1:10 |> filter(x -> x % 2 == 0) |> sum |> x -> x * 2

# dot vectorization
1:10 .|> x -> x * 2 .|> x -> x - 6
