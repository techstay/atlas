package tech.techstay.function

// By-name parameters allow you to pass an expression that will be evaluated only when it is used within the function.
def whileLoop(condition: => Boolean)(body: => Unit): Unit =
  if (condition) then
    body
    whileLoop(condition)(body)

@main def byNameParameters(): Unit =
  var i = 0
  whileLoop(i < 5) {
    print(s"$i ")
    i += 1
  }
  println()

  i = 0
  whileLoop(i > 5) {
    print(s"$i ")
    i += 1
  }
  println()
