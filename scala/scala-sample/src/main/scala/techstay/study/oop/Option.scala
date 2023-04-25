package techstay.study.oop

@main def option(): Unit =
  val parseInt = (str: String) => {
    try Some(Integer.parseInt(str))
    catch case e: Exception => None
  }
  val getInt = (str: String) =>
    parseInt(str) match
      case Some(i) => println(i)
      case None    => println("invalid number")

  getInt("3")
  getInt("yes")
