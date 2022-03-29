# frozen_string_literal: true
# typed: true

# some errors
class IDontKnowWhyError < StandardError
end

begin
  file = File.open('/etc/hosts', 'r')
  raise IDontKnowWhyError, 'I really dont know what happened'
# rescue clause is used to handle errors
rescue IDontKnowWhyError => e
  p e
# ensure clause will always be executed
ensure
  file&.close
  puts 'file closed'
end
