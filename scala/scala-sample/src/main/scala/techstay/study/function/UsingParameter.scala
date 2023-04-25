package techstay.study.function

type Config = Map[String, String]
@main def usingAndGiven(): Unit =
  // using context parameters
  def foo(a: Int, b: String)(using c: Config): Unit =
    println(s"a=$a, b=$b")
    println(s"config: $c")

  val config: Config = Map("a" -> "1", "b" -> "2")
  // specifying contextual parameters explicitly
  foo(2, "b")(using config)
  // given contextual parameters, then you don't need to specify it explicitly
  given Config = config
  foo(2, "b")
