import scala.util.Random

/* -------------------------------------------------------------------------- */
/*                              Pattern Matching                              */
/* -------------------------------------------------------------------------- */

val n = Random.nextInt(5)

def matchTest(n: Int) = n match
  case 0 => "zero"
  case 1 => "one"
  case 2 => "two"
  case _ => "other"

matchTest(n)
matchTest(0)
matchTest(1)
matchTest(2)
matchTest(3)

// Matching on strings
val str = "Hello, techstay! Have fun today."
val seek = str match
  case s"Hello, $name! Have fun $when." => s"Who: $name, when: $when"
  case _                                => "No match found"

// Matching on case classes

sealed trait Shape
case class Circle(radius: Double) extends Shape
case class Rectangle(width: Double, height: Double) extends Shape
case class Triangle(base: Double, height: Double) extends Shape

def area(shape: Shape): Double = shape match
  case Circle(radius)           => Math.PI * radius * radius
  case Rectangle(width, height) => width * height
  case Triangle(base, height)   => 0.5 * base * height

area(Circle(1.0))
area(Rectangle(4.0, 5.0))
area(Triangle(3.0, 4.0))

// Matching guards
def isSquare(shape: Shape): Boolean = shape match
  case Rectangle(width, height) if width == height => true
  case _                                           => false

isSquare(Rectangle(4.0, 4.0))
isSquare(Rectangle(4.0, 5.0))

// Matching on types
def typeMatch(value: Any): String = value match
  case s: String => s"String of length ${s.length}"
  case i: Int    => s"Integer: $i"
  case d: Double => s"Double: $d"
  case _         => "Unknown type"

typeMatch("Hello")
typeMatch(42)
typeMatch(3.14)
typeMatch(true)

// Binding patterns to variables
def matchShapes(shape: Shape): String = shape match
  case c @ Circle(radius) => s"$c is a circle with radius $radius"
  case r @ Rectangle(width, height) =>
    s"$r is a rectangle with width $width and height $height"
  case t @ Triangle(base, height) =>
    s"$t is a triangle with base $base and height $height"

matchShapes(Circle(2.0))
matchShapes(Rectangle(3.0, 4.0))
matchShapes(Triangle(5.0, 6.0))
