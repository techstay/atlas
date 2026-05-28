local function foo()
  print("foo")
end

foo()

-- variable arguments
local function sum(...)
  local s = 0
  local args = { ... }
  for i, v in ipairs(args) do
    s = s + v
  end
  return s
end

print(sum(1, 2, 3, 4, 5))
