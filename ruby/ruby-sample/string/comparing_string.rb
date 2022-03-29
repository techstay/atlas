# frozen_string_literal: true
# typed: true

# comparing strings

# compare equality
p 'Hello'.dup == 'Hello'
p 'Hello'.eql? 'World'

# compare alphabetical ranking
p 'Hello' <=> 'World'

# compare case-insensitively
p 'Hello'.casecmp 'hello'
