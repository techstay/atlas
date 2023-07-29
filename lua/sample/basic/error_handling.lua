-- pcall
local function foo(a, b)
  return a + b
end

local function test_foo(a, b, c)
  assert(foo(a, b) == c, string.format("foo(%d,%d) should be %d, but got %d\n", a, b, a + b, c))
end

if pcall(test_foo, 6, 4, 11) then
  print("test success")
else
  print("test failed")
end

-- xpcall
local function on_error(err)
  print("error:", err)
end

local status = xpcall(test_foo, on_error, 6, 4, 11)
print(status)
