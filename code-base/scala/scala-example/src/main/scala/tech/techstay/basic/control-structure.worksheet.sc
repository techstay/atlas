/* -------------------------------------------------------------------------- */
/*                                   If else                                  */
/* -------------------------------------------------------------------------- */

import scala.util.Random

val num = Random.nextInt(10)
val isOdd = (num: Int) => num % 2 == 0
val isEven = (num: Int) => num % 2 != 0

// if else
if isOdd(num) then println(s"$num is odd")
else if isEven(num) then println(s"$num is even")
else println(s"$num is not an integer")

// if expression
def choice[A](s: Seq[A]): A =
  s(Random.nextInt(s.length))

val inputs = Seq("o", "q", "y")
def testIf(input: String): String =
  val result =
    if input.toLowerCase() == "o" then "ok"
    else if input == "q" then "quit"
    else "unknown"
  result

for i <- inputs do println(testIf(i))

/* -------------------------------------------------------------------------- */
/*                                    Match                                   */
/* -------------------------------------------------------------------------- */

val x = 4
def matchTest(x: Int): String = x match
  case 1 => "one"
  case 2 => "two"
  // pattern guards
  case 3 if true => "three"
  // more cases into one line
  case 4 | 5 | 6 => "some bigger numbers"
  case what      => s"unknown number: $what"

for i <- 1 to 7 do println(matchTest(i))

/* -------------------------------------------------------------------------- */
/*                                    loop                                    */
/* -------------------------------------------------------------------------- */

// for comprehensions
val oddNumbers =
  for
    i <- 1 to 10
    if i % 2 != 0
  yield i

// for each
for i <- oddNumbers do print(s"$i ")
println()

// for guards
for
  i <- 1 to 6
  j <- 1 to 6
  if i + j == 6
do print(s"${(i, j)} ")
println()

// while loop
var i = 0
while i < 10 do
  print(s"$i ")
  i += 1
i
println()

/* -------------------------------------------------------------------------- */
/*                             Exception Handling                             */
/* -------------------------------------------------------------------------- */

try
  // making some mistakes
  val result = 1 / 0
catch
  case e: ArithmeticException =>
    println("I got some arithmetic error!")
    e.printStackTrace()
  case e: Exception =>
    println("I got some error!")
    e.printStackTrace()

finally println("doing some cleaning tasks")
