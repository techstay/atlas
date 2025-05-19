# frozen_string_literal: true
# typed: true

# Custom error class
class IDontKnowWhyError < StandardError
end

begin
  file = File.open('/etc/hosts', 'r')
  raise IDontKnowWhyError, 'I really don\'t know what happened'
# Rescue clause is used to handle errors
rescue IDontKnowWhyError => e
  p e
# Ensure clause will always be executed
ensure
  file&.close
  puts 'file closed'
end
