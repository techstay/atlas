##
str = "1+1"
expr = Meta.parse(str)

expr.head
expr.args

dump(expr)

expr2 = :(1 + 2 + 3)
dump(expr2)

##
x = 6
ex = :($x + 2)
dump(ex)

##
sym1 = :a
sym2 = :b
sym3 = Symbol("c")

sym3 === :c

##
eval(:(1 + 2))

eval(quote
  a = 5
  b = 6
  c = a + b
end)
