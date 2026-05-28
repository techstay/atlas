package tech.techstay.oop

object IdGenerator:
  private var currentId: Int = 0

  def generateId(): Int = {
    currentId += 1
    currentId
  }

end IdGenerator

@main def objectExample(): Unit =
  // Using the IdGenerator object to generate unique IDs
  val id1 = IdGenerator.generateId()
  val id2 = IdGenerator.generateId()
  val id3 = IdGenerator.generateId()

  println(s"Generated IDs: $id1, $id2, $id3")
