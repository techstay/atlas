# frozen_string_literal: true
# typed: true

# variable scope

# global variable
$global_variable = 100

# local variable
# starts with lower case letter or underscore
local_variable = 50
_local_variable2 = 25

# check scope of variable
puts(defined?($global_variable))
puts(defined?(local_variable))
puts(defined?(_local_variable2))

# system global variables
# see also: https://www.techotopia.com/index.php/Ruby_Variable_Scope
