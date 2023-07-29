local arr1 = { 1, 2, 3, 4, 5 }
local arr2 = {}

local function print_array(arr)
  for i, v in ipairs(arr) do
    io.write(string.format("%d ", v))
  end
  print()
end

print_array(arr1)

-- multi-dimensional array
for i = 1, 3, 1 do
  arr2[i] = {}
  for j = 1, 3, 1 do
    arr2[i][j] = 3 * (i - 1) + j
  end
end

for i = 1, 3 do
  for j = 1, 3 do
    io.write(string.format("%d ", arr2[i][j]))
  end
  print()
end

-- insertion and deletion
local arr3 = {}
table.insert(arr3, 5)
table.insert(arr3, 2)
table.insert(arr3, 1)
table.insert(arr3, 3, 4)
print_array(arr3)

table.remove(arr3, 4)
print_array(arr3)

table.sort(arr3)
print_array(arr3)
