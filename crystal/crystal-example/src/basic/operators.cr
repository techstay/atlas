def inspect_expression(expression)
  puts %(#{"-"*20} #{expression} #{"-"*20})
  p! expression
end

# Arithmetic operators
a = 6
b = 4

inspect_expression(a + b)
inspect_expression(a - b)
inspect_expression(a*b)
inspect_expression(a/b)
inspect_expression(a % b)

# Relational operators
inspect_expression(a == b)
inspect_expression(a != b)
inspect_expression(a > b)
inspect_expression(a < b)
inspect_expression(a >= b)
inspect_expression(a <= b)

# Logical operators
a = true
b = false

inspect_expression(a && b)
inspect_expression(a || b)
inspect_expression(!a)
