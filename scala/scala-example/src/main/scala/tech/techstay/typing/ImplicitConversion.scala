package tech.techstay.typing

// defining two classes
private class Foo(val baz: Int)
private class Bar(val baz: String)

// defining implicit conversions
given Conversion[Foo, Bar] with
  override def apply(x: Foo): Bar = Bar(x.baz.toString)

@main def implicitConversion(): Unit =
  // using implicit conversions
  def needBar(x: Bar): Unit = println(s"Bar is ${x.baz}")
  needBar(Foo(42))
