package tech.techstay.oop

class Person(var id: Int, var name: String, var age: Int):
  // constructors
  def this() =
    this(0, "", 0)

  def selfIntroduce(): Unit =
    println(s"I'm $name")

  override def toString: String =
    s"Person(id:$id, name:$name, age:$age)"

end Person

@main def clazz() =
  val p1 = Person(1, "techstay", 18)
  println(p1)
  // accessing public fields
  p1.name = "TECHSTAY"
  println(p1)
  p1.selfIntroduce()
