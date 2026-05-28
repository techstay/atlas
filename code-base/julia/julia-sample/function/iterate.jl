struct DoubleValue
  count::Integer
end

# implementing some methods
Base.iterate(v::DoubleValue, state=1) = state > v.count ? nothing : (state * 2, state + 1)
Base.eltype(::Type{DoubleValue}) = Int
Base.length(S::DoubleValue) = S.count

for i = DoubleValue(5)
  print("$(i) ")
end
println()
