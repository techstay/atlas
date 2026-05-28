# frozen_string_literal: true
# typed: true

require 'pathname'

# finding out root dir of the project
root = Pathname.getwd
root = root.parent until root.children.map(&:basename).inspect.include?('README.md')

# searching all ruby files and inserting `typed:true` if necessary
sub_directories = root.children.select(&:directory?)
sub_directories.each do |dir|
  ruby_files = dir.children.select { |e| e.extname == '.rb' }
  # check the first line of ruby files
  ruby_files.each do |file|
    content = file.read
    next if content.start_with? '# typed:'

    content.insert(0, "# typed: true\n\n")
    file.write(content)
    puts "Added static check to #{file}"
  end
end
