package techstay.study.typing

class MyRecord(elems: (String, Any)*) extends Selectable:
  private val fields = elems.toMap
  def selectDynamic(name: String): Any = fields(name)

type Person = MyRecord {
  val name: String
  val age: Int
}
@main def structuralType(): Unit =
  val person: Person =
    MyRecord("name" -> "techstay", "age" -> 18).asInstanceOf[Person]
  println(s"person(name:${person.name}, age:${person.age})")
