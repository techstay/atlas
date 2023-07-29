local arr1 = { 1, 2, 3, 4, 5, 6 }
for i = 1, #arr1, 1 do
  io.write(arr1[i])
end
print()

for i, _ in ipairs(arr1) do
  io.write(i)
end
print()
