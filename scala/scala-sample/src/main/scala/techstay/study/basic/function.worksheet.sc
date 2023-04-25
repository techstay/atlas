import scala.annotation.tailrec
// block
// the value of the block is the last expression in it
val value = {
  val a = 100
  val b = 200
  b
}
println(value)

// functions
def foo(a: Int, b: Int = 10): Int = a + b

def varargsFoo(args: Int*): Int =
  args.reduce((acc, e) => acc + e)

// default arguments
foo(10)
foo(10, 20)

// named arguments
foo(b = 2, a = 10)

// varargs
varargsFoo(1, 2)
varargsFoo(1, 2, 3, 4, 5)

// recursion
def factorial(n: Int): BigInt =
  if (n == 0 || n == 1) 1
  else factorial(n - 1) * n

@tailrec
final def factorial2(n: Int, accumulator: BigInt = 1): BigInt =
  if (n == 0 || n == 1) accumulator
  else factorial2(n - 1, n * accumulator)

factorial(10)
factorial2(100)
