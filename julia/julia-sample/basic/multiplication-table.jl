# 9*9 multiplication table
for i = 1:9
  for j = 1:i
    print("$(j)×$(i)=$(i*j)\t")
  end
  println()
end
