package tech.techstay.std

import scala.util.matching.Regex

@main def regularExpression(): Unit =
  val pattern: Regex = """\bb+c\b""".r
  val text = "abc bbc cbc bbbbbbc"
  for i <- pattern.findAllMatchIn(text) do println(i.group(0))

  // regex pattern matching
  def filterName(text: String): Unit =
    val namePattern = """(\w+)""".r
    val fullNamePattern = """(\w+)[\s,|:]*(\w+)""".r
    text match
      case namePattern(name) => println(s"Your name: $name")
      case fullNamePattern(firstname, lastname) =>
        println(s"Your full name: $firstname $lastname")
      case _ => println("Invalid format")

  filterName("techstay")
  filterName("Mike Clinton")
  filterName("Foo, Bar")
