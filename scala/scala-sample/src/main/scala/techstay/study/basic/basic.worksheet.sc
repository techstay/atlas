// single line comments

/** multiline comments multiline comments multiline comments multiline comments
  * multiline comments
  */

// integers
val b: Byte = 1
val s: Short = 2
val i: Int = 3
val l: Long = 4000000L

// float
val f: Float = 3.14f
val d: Double = 3.14159

// big
val bigInt: BigInt = 1
val bigDecimal: BigDecimal = 1e15

// boolean
val truth = true
val lie = false

// string
val c: Char = 'c'
val str: String = "abcd"
val rawString = raw"abcde{name}/\55"
val multilineString =
  """abcd
    |efg
    |xyz
    |""".stripMargin
println(multilineString)

// string interpolation
val name = "techstay"
val age = 18
println(s"My name is ${name.toUpperCase()}, my age is $age")

// immutable list
val numbers = List(1, 2, 3, 4)

// immutable set
val numberSet = Set(1, 1, 1, 3, 2, 2)

// immutable map
val numberMap = Map(1 -> 1, 2 -> 3, 3 -> 5)

// tuples
val sextet = (1, 2, 3, 4, 5, 6)

// readonly values
val thisIsAValue = 42

// variables
var thisIsAVariable = 42
thisIsAVariable = 84
println(thisIsAVariable)

// declaring two variables simultaneously
var x, y = 100
println((x, y))

// print multiplication table
for i <- 1 to 9 do
  for j <- 1 to i do print(s"$j*$i=${i * j}\t")
  println()
