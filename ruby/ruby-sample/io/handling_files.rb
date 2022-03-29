# frozen_string_literal: true
# typed: true

# new file
filename = 'temptemp.txt'
file = File.new(filename, 'w+')

# writing some data
file.puts 'line 1 line1'
file.puts 'line2 line2'

# moving cursor to the beginning of the file to read the content
file.rewind

# reading lines of the file
puts file.readline

# or reading the whole file
file.rewind
file.each { |line| puts line }

# finally closing the file
file.close
# check whether the file is closed
puts file.closed?

# renaming files
File.rename filename, 'temp.txt'

# deleting files
File.delete 'temp.txt'
