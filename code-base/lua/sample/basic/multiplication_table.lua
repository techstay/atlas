-- 九九乘法表
for i = 1, 9, 1 do
  for j = 1, i, 1 do
    io.write(string.format("%dx%d=%d\t", j, i, i * j))
  end
  print()
end
