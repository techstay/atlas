# frozen_string_literal: true
# typed: true

contact = { techstay: 100, zhang3: 40, li4: 60 }

# getting keys and vlaues
puts "keys: #{contact.keys.inspect}"
puts "values: #{contact.values.inspect}"

# check existence of keys and values
p contact.key?(:techstay)
p contact.value?(100)
