// some conditions
val num = 10
val isOdd = num % 2 == 0
val isEven = num % 2 != 0

// if then
if isOdd then println(s"$num is odd")
else if isEven then println(s"$num is even")
else println(s"$num is not an integer")

// if expression
val input = "o"
val choice =
  if input == "o" then "ok"
  else if input == "q" then "quit"
  else "unknown"
println(s"Your choice is $choice")

// match
val x = 4
val str = x match
  case 1 => "one"
  case 2 => "two"
  // pattern guards
  case 3 if true => "three"
  // more cases into one line
  case 4 | 5 | 6 => "some bigger numbers"
  case what      => s"unknown number: $what"

println(str)
// for
val numbers = List.range(1, 6)
while i <= 5 do
  print(s"$i ")
  i += 1
println()
// for expressions
val oddNumbers =
  for
    i <- 1 to 10
    if i % 2 != 0
  yield i
for i <- numbers do print(s"$i ")
println()

// for guards
for
  i <- 1 to 6
  j <- 1 to 6
  if i + j == 6
do print(s"${(i, j)} ")
println()
// while
var i = 0
println(oddNumbers)

// raising exceptions
try
  // making some mistakes
  val result = 1 / 0
catch
  case e: NullPointerException => e.printStackTrace()
  case e: ArithmeticException =>
    println("I got some arithmetic error!")
    e.printStackTrace()
finally println("doing some cleaning tasks")
