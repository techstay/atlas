package tech.techstay.function

@main def highOrderFunction(): Unit =
  // lambdas
  val add = (a: Int, b: Int) => a + b
  println(add(3, 4))

  // high order functions
  val numbers = Seq(1, 2, 3, 4, 5)
  val square = numbers.map(x => x * x)
  println(square)
  println(numbers.map(_ * 2))

  def foo(callback: () => Unit): Unit =
    callback()
  foo(() => { println("hello") })

  // currying
  def bar(x: Int)(y: Int): Unit =
    println((x, y))
  // the second approach implementing currying
  def bar2(x: Int): Int => Unit =
    (y: Int) => println((x, y))
  bar(1)(2)
  bar2(1)(2)
