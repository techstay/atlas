# frozen_string_literal: true
# typed: true

contact = { techstay: 100, Jackson: 40, Leonardo: 60 }
p contact

contact.each { |k, v| puts "#{k} => #{v}" }

contact.each_key do |k|
  print "#{k},"
end
puts

contact.each_value do |v|
  print "#{v},"
end
puts
