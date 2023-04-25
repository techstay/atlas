package techstay.study.function

@main def partialFunction(): Unit =
  def foo(x: Int, y: Int) = x + y
  def sum10 = foo(10, _)
  println(sum10(5))
