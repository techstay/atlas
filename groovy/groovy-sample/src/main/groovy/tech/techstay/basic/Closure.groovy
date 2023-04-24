package tech.techstay.basic

def closure1 = { -> }
def closure2 = { "default $it" }
def closure3 = { String a -> a.toUpperCase() }
def closure4 = { a, b -> a + b }

println(closure1.call())
println(closure2())
println(closure2(8))
println(closure3.call('c'))
println(closure4(3, 8))

// currying
def plus = closure4
def twoPlus = plus.curry(2)
println(twoPlus(6))

// memoization
// slow fibonacci
def fib
fib = { n -> n < 2 ? n : fib(n - 1) + fib(n - 2) }

println(fib(25))

// fast fibonacci
fib = { BigInteger n -> n < 2 ? n : fib(n - 1) + fib(n - 2) }.memoize()
println(fib(50g))

// trampoline
def factorial
factorial = { int n, def acc = 1g ->
  if (n < 2) return acc
  factorial.trampoline(n - 1, n * acc)
}

factorial = factorial.trampoline()
println(factorial(200))
