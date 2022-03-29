# frozen_string_literal: true
# typed: true

contact = { techstay: 100, zhang3: 40, li4: 60 }
p contact

contact.each { |k, v| puts "key: #{k} value: #{v}" }
contact.each_key do |k|
  print "#{k},"
end
puts

contact.each_value do |v|
  print "#{v},"
end
puts
