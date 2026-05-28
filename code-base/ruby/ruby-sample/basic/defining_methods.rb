# frozen_string_literal: true
# typed: true

# defining a method

def print_name(name)
  puts(name)
end

print_name 'techstay'

# method arguments
def plus(a, b)
  a + b
end

puts(plus(1, 2))

# methods with variable arguments
def print_names(*names)
  names.each { |name| print "#{name} " }
  puts
end

print_names('techstay')
print_names('techstay', 'Jackson', 'Tanaka')

# default parameters
def hello(name = 'techstay')
  puts "Hello #{name}"
end

hello
hello 'Jackson'

# method alias
alias add plus
puts(add(3, 5))

# recursive methods
def fib(n)
  return 1 if [0, 1].include?(n)

  fib(n - 1) * n
end

puts "fib(5)=#{fib(5)}"
