# frozen_string_literal: true
# typed: true

require('English')

# executing external commands

files = `ls`
files.split("\n").each do |file|
  print "#{file} "
end
puts

# checking status and returning of commands
# $? stands for the status of the last executed command
p $?.success?
p $CHILD_STATUS.exitstatus
