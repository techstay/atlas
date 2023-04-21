# frozen_string_literal: true
# typed: true

# add sorbet static check comment to ruby files.
require 'pathname'

puts 'Press y to continue...'
prompt = gets
exit if prompt.downcase != 'y'

# finding out root dir of the project
root = Pathname.getwd
root = root.parent until root.children.map(&:basename).inspect.include?('README.md')

# searching all ruby files and insering typed:true if necessary
root.children.each do |file|
  next unless file.extname == '.rb'

  # check the first line of ruby files
  content = file.read
  next if content.start_with? '# typed:'

  content.insert(0, "# typed: true\n\n")
  file.write(content)
  puts "Added static check to #{file}"
end
