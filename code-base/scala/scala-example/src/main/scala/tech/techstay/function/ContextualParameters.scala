package tech.techstay.function

type Config = Map[String, String]

// Contextual parameters
def foo(a: Int, b: String)(using c: Config): Unit =
  println(s"a=$a, b=$b")
  println(s"config: $c")

@main def contextualParameters(): Unit =
  val config: Config = Map("x" -> "1", "y" -> "2")

  // specifying contextual parameters explicitly
  foo(2, "b")(using config)

  // given contextual parameters, then you don't need to specify it explicitly
  given Config = config
  foo(2, "b")
