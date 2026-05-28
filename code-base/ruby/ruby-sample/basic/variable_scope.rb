# frozen_string_literal: true
# typed: true

require('English')

# variable scope

# global variable
$globalv = 100

# local variable
# starts with lower case letter or underscore
localv = 50

# check scope of variable
puts(defined?($globalv))
puts(defined?(localv))

# system global variables
# see also: https://www.techotopia.com/index.php/Ruby_Variable_Scope

# Ruby Interpreter Process ID
puts $$
# This is equivalent to `$$`
puts $PROCESS_ID
