# multiline functions
result = map(x -> begin
    if x % 2 == 0
      return "yes"
    else
      return "no"
    end
  end, [1, 2, 3, 4, 5])

println(result)

# do block
result = map([1, 2, 3, 4, 5]) do x
  if x % 2 == 0
    return "yes"
  else
    return "no"
  end
end

println(result)
