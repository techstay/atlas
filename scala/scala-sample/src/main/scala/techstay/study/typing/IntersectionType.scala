package techstay.study.typing

trait X
trait Y
class Z extends X, Y:
end Z

@main def intersectionType(): Unit =
  def iNeedAAndB(o: X & Y): Unit =
    println(s"$o is A and B")
  val c = Z()
  iNeedAAndB(c)
