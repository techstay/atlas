package techstay.study.typing

private class Base(name: String):
  override def toString: String = s"(name:$name)"
private case class A(name: String) extends Base(name = name)

private case class B(name: String) extends Base(name = name)
@main def unionType(): Unit =
  var obj: A | B = A("hello")
  println(obj)
  obj = B("techstay")
  println(obj)

  // union type pattern matching
  obj match
    case A(name)  => println(s"A:$name")
    case B(name)  => println(s"B:$name")
    case someElse => println(someElse)
