package techstay.study.oop

private class Person(var id: Int, var name: String, var age: Int):
  // constructors
  def this() =
    this(0, "", 0)

  def speak(): Unit =
    println(s"I'm $name")

  override def toString: String =
    s"Person(id:$id, name:$name, age:$age)"

end Person

@main def clazz(): Unit =
  val p1 = Person(1, "techstay", 18)
  // accessing public fields
  p1.name = "TECHSTAY"
  println(p1)
