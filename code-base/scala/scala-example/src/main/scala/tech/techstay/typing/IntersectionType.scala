package tech.techstay.typing

trait X
trait Y
class Z extends X, Y

def iNeedAAndB(o: X & Y): Unit =
  println(s"$o is A and B")

@main def intersectionType(): Unit =
  val c = Z()
  iNeedAAndB(c)
