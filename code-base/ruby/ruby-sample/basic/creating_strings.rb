# frozen_string_literal: true
# typed: true

# creating strings

puts 'some content of strings'

# custom delimiter
puts %(some content of string to avoid double quotes"" or singe quotes'')

# here documents
puts <<~STRING
  this is a long text
  may contain many lines
  end with 'end of line'.
STRING
