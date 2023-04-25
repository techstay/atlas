package yitian.study.basic

/**
  * 函数的特性
  */
object Functions {
  def main(args: Array[String]): Unit = {
    simpleFunc(100)
    callByNameFunc(100)
    simpleFunc(simpleFunc(100))
    callByNameFunc(simpleFunc(100))

    varargFunc(1, 2)
    varargFunc(1, 2, 3, 4, 5)

    defaultValueFunc()
    defaultValueFunc(15)
    defaultValueFunc(msg = "Fuck", num = 10)
    nestingFunc()
    partialFunc()

    println(factorial(100))
    println(factorial2(100))

    anonymousFunc()

    highOrderFunc(() => 100)

    curryingFunc("fuck")("shit")

    closureFunc()
  }

  def simpleFunc(num: Int): Int = {
    println("In simpleFunc")
    println(num)
    num
  }

  /**
    * 按名传递函数，
    * 参数只有在函数内使用的时候才计算值
    *
    * @param num
    */
  def callByNameFunc(num: => Int): Unit = {
    println("In callByNameFunc")
    println(num)
  }

  def varargFunc(num: Int*): Unit = {
    for (n <- num) {
      print(n)
    }
    println()
  }

  def defaultValueFunc(num: Int = 5, msg: String = ""): Unit = {
    println("num=" + num)
  }

  /**
    * 嵌套函数
    */
  def nestingFunc(): Unit = {
    def innerFunc(): Unit = {
      println("Inner func")
    }

    innerFunc()
  }

  /**
    * 偏函数
    */
  def partialFunc(): Unit = {

    def print(num: Int, msg: String): Unit = {
      println(num, msg)

    }

    val printMsg = print(10, _: String)

    printMsg("msg1")
    printMsg("msg2")
  }

  /**
    * 求阶乘的递归实现
    *
    * @param n
    * @return
    */
  def factorial(n: BigInt): BigInt = {
    if (n == 0 || n == 1) {
      1
    } else {
      n * factorial(n - 1)
    }
  }

  /**
    * 求阶乘的尾递归版本
    *
    * @param n
    * @param result
    * @return
    */
  def factorial2(n: BigInt, result: BigInt = 1): BigInt = {
    if (n == 0 || n == 1) {
      result
    } else {
      factorial2(n - 1, n * result)
    }
  }

  /**
    * 匿名函数
    */
  def anonymousFunc(): Unit = {
    val fuck = (x: Int) => println(x)
    val shit = new Function[Int, Unit] {
      def apply(x: Int) = println(x)
    }

    fuck(100)
    shit(100)
  }

  /**
    * 高阶函数
    */
  def highOrderFunc[T](x: T): Unit = {
    println(x)
  }

  /**
    * 函数柯里化
    */
  def curryingFunc(fuck: String)(shit: String): Unit = {
    println(fuck, shit)
  }

  def closureFunc(): Unit = {
    val i = 5

    val fun = (n: Int) => println(i * n)

    fun(2)
    fun(3)
  }
}
