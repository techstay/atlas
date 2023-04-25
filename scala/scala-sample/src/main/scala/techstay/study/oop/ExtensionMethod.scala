package techstay.study.oop

extension (p: Int)
  def giveMeARandomNumber(): Int =
    import scala.util.Random.between
    between(1, 101)

@main def extensionMethod(): Unit =
  println(1.giveMeARandomNumber())
