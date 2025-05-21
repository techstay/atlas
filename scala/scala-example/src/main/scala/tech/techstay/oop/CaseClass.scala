package tech.techstay.oop

case class Point(x: Double, y: Double)

@main def caseClassExample(): Unit = {
  val p1 = Point(1.0, 2.0)
  val p2 = Point(1, 2)

  println(p1)
  println(p2)

  // comparing by values
  println(p1 == p2)

  // accessing fields
  println(s"Point coordinates: (${p1.x}, ${p1.y})")
}
