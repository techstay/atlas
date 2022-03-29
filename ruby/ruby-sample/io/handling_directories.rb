# frozen_string_literal: true
# typed: true

# getting working directories
pwd = Dir.pwd
puts pwd

# changing working directories
Dir.chdir pwd

# listing directories
Dir.entries('.').each { |file| puts file }
# or
Dir.foreach('.') { |file| puts file }
