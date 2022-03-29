# frozen_string_literal: true
# typed: true

dice = {}

N = 100_000

N.times do |_i|
  index = rand(1..6)
  dice[index] = dice.fetch(index, 0) + 1
end

p dice
