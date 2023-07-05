function f(a, b; foo="foo", bar="bar")
  println(a, b)
  println(foo, bar)
end

f(1, 2)
f(1, 2, foo="fake")
f(1, 2, foo="hello", bar="world")
