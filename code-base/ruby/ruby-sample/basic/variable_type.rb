# frozen_string_literal: true
# typed: true

require('awesome_print')

# Check variable type
a = 100
ap a.is_a?(Integer)

# Variable type
ap(a.class)

# Converting

ap(a.to_s)
ap(a.to_s(2))
ap(a.to_s(8))
ap(a.to_s(16))
ap(a.to_f)

s = '100.05'
ap(s.to_f)
ap(s.to_i)
