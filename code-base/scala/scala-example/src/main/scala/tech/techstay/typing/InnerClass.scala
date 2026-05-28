package tech.techstay.typing

class Parent(val name: String):
  class Child(val name: String)

  def feed(children: Child*) =
    println(s"$name is feeding ${children.map(_.name).mkString(", ")}")

  def feedAll(children: Parent#Child*): Unit =
    println(s"$name is feeding ${children.map(_.name).mkString(", ")}")

@main def innerClassExample(): Unit =
  val parent = Parent("Jackson")
  val child = parent.Child("Jack")

  println(s"Parent name: ${parent.name}")
  println(s"Child name: ${child.name}")

  val anotherParent = Parent("Smith")
  val anotherChild = anotherParent.Child("Sally")

  // Inner classes are bound to their parent instance
  parent.feed(child)
  // can't compile
  // parent.feed(child, anotherChild)
  // This works
  anotherParent.feedAll(child, anotherChild)
