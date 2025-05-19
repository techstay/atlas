# frozen_string_literal: true
# typed: true

contact = { techstay: 100, Leonardo: 40, jack: 60 }

# getting keys and values
puts "keys: #{contact.keys.inspect}"
puts "values: #{contact.values.inspect}"

# checking existence of keys and values
p contact.key?(:techstay)
p contact.value?(100)

# getting value if not present
p contact.fetch(:unknown, 0)
