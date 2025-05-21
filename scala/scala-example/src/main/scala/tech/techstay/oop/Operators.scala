package tech.techstay.oop

case class Vector(x: Int, y: Int):
  // Define operators
  def +(other: Vector): Vector = Vector(x + other.x, y + other.y)
  def -(other: Vector): Vector = Vector(x - other.x, y - other.y)
  def *(scalar: Int): Vector = Vector(x * scalar, y * scalar)
  def /(scalar: Int): Vector = Vector(x / scalar, y / scalar)
  override def toString: String = s"Vector($x, $y)"

@main def operators(): Unit =
  val v1 = Vector(1, 2)
  val v2 = Vector(3, 4)
  println(v1 + v2)
  println(v1 - v2)
  println(v1 * 2)
  println(v1 / 2)
