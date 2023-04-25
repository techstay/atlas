package techstay.study.oop

import techstay.study.oop.Foo.count

private class Foo(name: String):
  count += 1

// companion object
object Foo:
  private var count = 0
  def printCounts(): Unit =
    println(count)

@main def companionObject(): Unit =
  Foo("a")
  Foo("b")
  Foo.printCounts()
