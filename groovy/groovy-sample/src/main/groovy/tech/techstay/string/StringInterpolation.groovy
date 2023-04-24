package tech.techstay.string

def name = 'techstay'
def greeting = "Hello, ${name}"
def info = "${name} is ${18 * 2 - 10} years old."

println(greeting)
println(info)

// lazy evaluates of string interpolation
def number = 1
def eagerString = "eager tring value: ${number}"
def lazyString = "lazy string value: ${-> number}"

number = 2
println(eagerString)
println(lazyString)

// dollar slashy strings
def dollarSlashy = $/
"abc\n"
  $$xyz
  $name
'abc\t'
/$
println(dollarSlashy)
