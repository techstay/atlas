package tech.techstay.function

@main def multipleParameterLists(): Unit =
  def add(x: Int)(y: Int): Int = x + y

  // Using the function with multiple parameter lists
  val result1 = add(10)(5)
  val result2 = add(20)(15)

  println(s"Result of add(10)(5): $result1")
  println(s"Result of add(20)(15): $result2")
