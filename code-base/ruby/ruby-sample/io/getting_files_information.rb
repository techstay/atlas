# frozen_string_literal: true
# typed: true

require('awesome_print')

# checking existence of files
nonexistent_filename = 'test.txt'
existent_filename = __FILE__

ap "exist? #{File.exist? nonexistent_filename}"

# finding out a file is a file or a directory
ap "is file? #{File.file? existent_filename}"
ap "is dir? #{File.directory? File.dirname(__FILE__)}"

# identifying whether a file is readable, writable and executable
ap "is readable? #{File.readable? existent_filename}"
ap "is writable? #{File.writable? existent_filename}"
ap "is executable? #{File.executable? existent_filename}"

# getting size of a file
ap "size: #{File.size existent_filename}"
ap "is empty? #{File.zero? existent_filename}"

[__FILE__, Dir.pwd, '/dev/zero'].each { |file| ap "ftype: #{File.ftype file}" }

# getting time information of files
ap File.ctime __FILE__
ap File.mtime __FILE__
ap File.atime __FILE__
