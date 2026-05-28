# varargs functions
function combine(a, b, rest...)
  (a, b, rest...)
end

println(combine(1, 2, 3, 4, 5))
