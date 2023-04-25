package yitian.study.basic

/**
  * 控制流：条件和循环语句
  */
object ControllFlow {
  def main(args: Array[String]): Unit = {

    conditionalStatements()
    circularStatements()
  }

  def conditionalStatements(): Unit = {
    if (3 > 4) {
      println("3>4")
    } else if (4 > 3) {
      println("4>3")
    } else {
      println("3=4")
    }


  }

  def circularStatements(): Unit = {
    //while循环
    var it = 0
    while (it <= 5) {
      print(it)
      it += 1
    }
    println

    //do-while循环
    it = 0
    do {
      print(it)
      it += 1
    } while (it <= 5)
    println

    //for循环
    for (i <- 1 to 10) {
      print(i)
    }
    println


    for (i <- 1 until 10) {
      print(i)
    }
    println

    for (a <- 1 to 3; b <- 1 to 3) {
      print(a, b)
    }
    println()

    //foreach循环
    val list = List(1, 2, 3, 4, 5)
    for (e <- list) {
      print(e)
    }
    println

    //for if
    for (a <- list if a % 2 == 0) {
      print(a)
    }
    println

    //for yield
    val result = for {
      a <- 1 to 10 if a % 2 == 0
    } yield a
    println(result)

  }
}
