# frozen_string_literal: true
# typed: true

text = 'aaa aab abb bbc bbcc caa bcc bdddd'

# searching and returning index of the first match
p text =~ /aab/
p text =~ /ddd/

# returning first matched string
p text[/\w{4,}/]

# replacing strings
p 'Ruby is the best programming language in the world.'.gsub(/Ruby/, 'Python')

# searching all matched
p text.scan(/\bb\w+\b/)

# case insensitive search
p 'aaA'.match(/aaa/i)
