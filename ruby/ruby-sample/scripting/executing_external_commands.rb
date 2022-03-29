# frozen_string_literal: true
# typed: true

# executing external commands

files = `ls`
puts files

# checking status and returning of commands
# $? stands for the status of the last executed command
p $?.success?

return_value = system 'pwd'
