# frozen_string_literal: true
# typed: true

# case statement

fruit = 'apple'

color = case fruit
        when 'apple' then 'red'
        when 'orange' then 'orange'
        when 'watermelon' then 'green'
        else 'other'
        end

puts(color)

# number range case
score = 60
puts(case score
     when 0...60 then 'fail'
     when 60...70 then 'progressive'
     when 70...80 then 'good'
     when 80...100 then 'excellent'
     when 100 then 'perfect'
     else 'perfect'
     end)
