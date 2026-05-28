name = "John"

puts "Hello #{name}"
puts "Hello #{name.upcase}"
puts "Hello #{name.downcase}"

puts "reverse: #{name.reverse}"
puts "length: #{name.size}"
puts "include? 'oh': #{name.includes?("oh")}"

puts "index of 'o': #{name.index("o")}"

puts "split: #{name.split("o")}"
puts "join: #{name.split("o").join("-")}"

puts "replace: #{name.gsub("o", "a")}"

puts "repeat: #{name * 3}"
