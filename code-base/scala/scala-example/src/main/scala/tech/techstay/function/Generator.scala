package tech.techstay.function

@main def generator(): Unit =
  val numbers = (n: Int) => {
    for i <- 1 to n
    yield i
  }

  println(numbers(5))
