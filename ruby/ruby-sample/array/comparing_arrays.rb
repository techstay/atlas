# frozen_string_literal: true
# typed: true

# comparing arrays

a1 = [1, 2, 3]
a2 = [1, 2, 3]
a3 = [1, 2, 3.0]
a4 = [1, 3, 2]

puts("a1 ==a3 ? #{a1 == a3}")
puts("a1 eql? a3 ? #{a1.eql?(a3)}")
puts("a1 eql? a2 ? #{a1.eql?(a2)}")
puts("a1 <=> a4 ? #{a1 <=> a4}")
