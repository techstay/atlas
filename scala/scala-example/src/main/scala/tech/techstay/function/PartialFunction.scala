package tech.techstay.function

@main def partialFunction(): Unit =
  val foo = (x: Int, y: Int) => x + y
  val sum10 = foo(10, _)
  println(sum10(5))
