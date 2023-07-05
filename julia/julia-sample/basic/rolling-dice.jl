# rolling dice
const N = 500000
let
  dice = Dict{Integer,Integer}()
  for _ in 1:N
    k = rand(1:6)
    v = get(dice, k, 0)
    dice[k] = v + 1
  end
  println(dice)
end
