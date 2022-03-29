# frozen_string_literal: true
# typed: true

# check variable type
a = 100
p(a.is_a?(Integer))

# variable type
p(a.class)

# convert variable

# to string
p(a.to_s)
p(a.to_s(2))
p(a.to_s(8))
p(a.to_s(16))
# to float
p(a.to_f)
