# frozen_string_literal: true
# typed: true

# bigdecimal
require 'bigdecimal'

sum1 = 0.0
sum2 = BigDecimal('0')

1000.times do |_i|
  sum1 += 0.001
  sum2 += BigDecimal('0.001')
end

p sum1, sum2.to_f
