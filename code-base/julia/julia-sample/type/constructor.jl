struct Foo
  bar::Integer
  baz::Integer
  # inner constructors
  Foo(x, y) = x >= 0 && y >= 0 ? new(x, y) : new(abs(x), abs(y))
end

# outer constructors
Foo(x) = Foo(x, 0)
Foo() = Foo(0)

a = Foo(1, 2)
b = Foo(-1, -2)
c = Foo(3)
d = Foo()

println([a, b, c, d])
