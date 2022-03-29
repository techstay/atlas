# frozen_string_literal: true
# typed: true

# checking existence of files
nonexistent_filename = 'test.txt'
existent_filename = __FILE__

puts "exist? #{File.exist? nonexistent_filename}"

# finding out a file is a file or a directory
puts "is file? #{File.file? existent_filename}"
puts "is dir? #{File.directory? File.dirname(__FILE__)}"

# identifying whether a file is readable, writable and executable
puts "is readable? #{File.readable? existent_filename}"
puts "is writable? #{File.writable? existent_filename}"
puts "is executable? #{File.executable? existent_filename}"

# getting size of a file
puts "size: #{File.size existent_filename}"
puts "is empty? #{File.zero? existent_filename}"

[__FILE__, Dir.pwd, '/dev/zero'].each { |file| puts "ftype: #{File.ftype file}" }

# getting time information of files
puts File.ctime __FILE__
puts File.mtime __FILE__
puts File.atime __FILE__
