package tech.techstay.std

import scala.io.StdIn.readLine

@main def input() =
  println("Input your name:")
  val name = readLine()
  println(s"Hello, ${name.capitalize}!")
