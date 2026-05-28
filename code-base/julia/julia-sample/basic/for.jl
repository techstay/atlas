for i = 1:5
  print(i)
end

println()

# equivalent to = or ∈
for j in 1:5
  print(j)
end

println()

for (index, value) ∈ enumerate(5:-1:1)
  print("($(index), $(value)) ")
end
println()
