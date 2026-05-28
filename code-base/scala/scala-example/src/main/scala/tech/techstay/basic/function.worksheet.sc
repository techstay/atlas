import scala.annotation.tailrec

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

// blocks
val value = {
  val a = 100
  val b = 200
  a + b
}

// functions
def add(a: Int, b: Int = 10): Int = a + b

// anonymous functions (lambdas)
val minus = (a: Int, b: Int) => a - b

val theAnswerOfTheUniverse = () => 42

def addAll(args: Int*) =
  args.reduce((acc, e) => acc + e)

// no parameters
theAnswerOfTheUniverse()

// default arguments
add(10)
add(10, 20)

// named arguments
add(b = 2, a = 10)

// varargs
addAll(1, 2)
addAll(1, 2, 3, 4, 5)

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
