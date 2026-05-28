local function foo(a, b)
  return a + b
end

assert(foo(6, 4) == 10, "foo(6,4) should be 10")
assert(foo(6, 4) == 8, "foo(6,4) should be 10")
