package tech.techstay.oop

import scala.util.Random

object ID:

  def apply(name: String) = s"$name--${Random.nextLong()}"

  def unapply(id: String): Option[String] =
    val array = id.split("--")
    if array.tail.nonEmpty then Some(array.head)
    else None

@main def extractorObject(): Unit =
  // This calls the apply method
  val id = ID("techstay")
  println(s"ID is $id")

  id match
    // This calls the unapply method
    case ID(name) => println(s"Extracted name is $name")
    case _        => println("No match found")
