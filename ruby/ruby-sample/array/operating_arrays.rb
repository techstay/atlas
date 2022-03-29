# frozen_string_literal: true
# typed: true

# combining arrays

a1 = [1, 2, 3]
a2 = [4, 5]
p(a1 + a2)
p a1.concat(a2)
p(a1 << 6 << 7)

# setting operations
a1 = (10..16).to_a
a2 = (14..18).to_a
p(a1 - a2)
p(a2 - a1)
p(a1 & a2)
p(a1 | a2)

# removing duplicated elements
a1 = Array.new(7, 'a')
p a1.uniq

# array as stack
a1 = [1]
a1.push(2)
a1.push(3)
a1.pop
a1.push(4)
p a1

# join an array to one string
p [1, 2, 3, 4].join '-'
