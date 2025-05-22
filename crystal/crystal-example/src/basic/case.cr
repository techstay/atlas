score = 80

grade = case score
        when 0..59
          "F"
        when 60..69
          "D"
        when 70..79
          "C"
        when 80..89
          "B"
        when 90...100
          "A"
        when 100
          "S"
        else
          "Invalid score"
        end

p! grade
