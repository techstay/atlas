# Hash Declaration
hash1 = Hash(String, Int32).new
hash2 = {} of String => Int32
hash3 = {"a" => 1, "b" => 2, "c" => 3}

# Adding and Accessing Elements
hash3["d"] = 4
p! hash3["a"]

# Removing Elements
hash3.delete("b")
p! hash3

# Iterating Over Hash
hash3.each do |key, value|
  puts "#{key} => #{value}"
end

# Hash Length
p! hash3.size

# Checking if a Key Exists
p! hash3.has_key?("a")

# Checking if a Value Exists
p! hash3.has_value?(1)

# Merging Hashes
hash4 = {"e" => 5, "f" => 6}
p! hash3.merge(hash4)

# Getting Values If Key not found
p! hash3.fetch("g", "default value")

# Iterating Over Hash
hash3.each do |key, value|
  puts "#{key} => #{value}"
end
