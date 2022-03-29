# frozen_string_literal: true
# typed: true

# creating strings

p 'some content of strings'

# custom delimiter
p %(some content of string to avoid double quotes"" or singe quotes'')

# here documents
p <<~EOL
  this is a long text
  may contain many lines
  end with 'end of line'
EOL
