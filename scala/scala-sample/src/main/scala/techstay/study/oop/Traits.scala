package techstay.study.oop

private trait HasLegs:
  def numLegs: Int
  def walk(): Unit

private trait HasTail:
  def wagTail(): Unit

class Dog(name: String) extends HasLegs, HasTail:
  override def numLegs: Int = 4

  override def walk(): Unit = println(s"$name is walking")

  override def wagTail(): Unit = println(s"$name wags tail")

@main def traits(): Unit =
  val dog = Dog("tiger")
  dog.walk()
  dog.wagTail()
