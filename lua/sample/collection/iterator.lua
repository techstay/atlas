-- stateless iterators
local function number_iterator(max, current)
  if current < max then
    current = current + 1
    return current, current
  end
end

for i, n in number_iterator, 5, 0 do
  io.write(string.format("%d, %d\n", i, n))
end

-- stateful iterators
local function square_iterator(n)
  local index = 0
  return function()
    index = index + 1
    if index <= n then
      return index ^ 2
    end
  end
end

for i in square_iterator(5) do
  io.write(string.format("%d ", i))
end
