def inspect_variable(var)
  max_header_width = 80
  header = "Inspecting value: #{var}"
  padding_width = ((max_header_width - header.size) / 2).ceil.to_i

  puts %(#{"-"*padding_width}#{header}#{"-"*(80 - header.size - padding_width)})
  p! var, typeof(var)
end

name = "Jack"
age = 32

inspect_variable(name)
inspect_variable(age)
inspect_variable(1.0)
inspect_variable(1)
inspect_variable(true)
inspect_variable(false)
inspect_variable(nil)
inspect_variable(:hello)
