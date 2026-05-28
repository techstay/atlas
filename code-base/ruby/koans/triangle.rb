# typed: true

# Triangle Project Code.

# Triangle analyzes the lengths of the sides of a triangle
# (represented by a, b and c) and returns the type of triangle.
#
# It returns:
#   :equilateral  if all sides are equal
#   :isosceles    if exactly 2 sides are equal
#   :scalene      if no sides are equal
#
# The tests for this method can be found in
#   about_triangle_project.rb
# and
#   about_triangle_project_2.rb
#
def triangle(a, b, c)
  # first verify a, b, c
  sides = [a, b, c].sort!
  sides.each { |e| raise TriangleError, 'Triangle sides should be greater than 0' unless e.positive? }
  raise TriangleError, 'Invalid triangle sides' if sides[0] + sides[1] <= sides[2]

  if a == b && a == c
    :equilateral
  elsif (a == b) ^ (b == c) ^ (a == c)
    :isosceles
  else
    :scalene
  end
end

# Another solution with help of Array.uniq
# def triangle(a, b, c)
#   case [a, b, c].uniq.size
#   when 1 then :equilateral
#   when 2 then :isosceles
#   when 3 then :scalene
#   end
# end

# Error class used in part 2.  No need to change this code.
class TriangleError < StandardError
end
