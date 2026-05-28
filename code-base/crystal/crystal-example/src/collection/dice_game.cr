dice_game = Hash(Int32, Int32).new

1000000.times do
  n = rand(1..6)
  dice_game[n] = dice_game.fetch(n, 0) + 1
end

p! dice_game
