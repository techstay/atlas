N = 100000

local dice = {}

for _ = 1, N do
  local k = math.random(1, 6)
  if dice[k] == nil then
    dice[k] = 1
  else
    dice[k] = dice[k] + 1
  end
end

for i = 1, 6 do
  io.write(string.format("%d=>%d, ", i, dice[i]))
end
