package techstay.study.typing

opaque type MyNumber = Int
object MyNumber:
  def apply(n: Int): MyNumber = n
extension (x: MyNumber)
  def +(myNumber: MyNumber): MyNumber = x + myNumber
  def -(myNumber: MyNumber): MyNumber = x - myNumber
@main def opaqueType(): Unit =
  val a = MyNumber(5)
  val b = MyNumber(6)
  println(a + b)
  println(a - b)
