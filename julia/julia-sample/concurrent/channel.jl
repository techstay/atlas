##

chnl = Channel() do ch
  foreach(i -> put!(ch, i), 1:5)
end

for i = chnl
  @show i
end
