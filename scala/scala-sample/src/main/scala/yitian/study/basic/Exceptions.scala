package yitian.study.basic

/**
  * 异常处理
  */
object Exceptions {
  def main(args: Array[String]): Unit = {
    catchExceptions()

  }

  def catchExceptions(): Unit = {
    try {
      val result = 1 / 0
      println(result)
    }
    catch {
      case ex: NullPointerException => {
        println(ex)
      }
      case ex: ArithmeticException => {
        println(ex)
      }
    }
    finally{
      println("End try-catch")
    }
  }
}
