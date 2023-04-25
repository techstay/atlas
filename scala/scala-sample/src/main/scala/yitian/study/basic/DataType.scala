package yitian.study.basic

//单行注释
/*
多行
注释*/

/**
  * Scala的基本数据类型
  *
  */
object DataType {
  def main(args: Array[String]): Unit = {
    numbers()
    booleans()
    strings()
    declaration()
  }

  def numbers(): Unit = {
    //整数类型
    val b: Byte = 15
    val s: Short = 150
    val i: Int = 100000
    val l: Long = 1000000000000L
    //浮点数
    val f: Float = 15.6F
    val d: Double = 3.1415926

    val bigInt: BigInt = 100
    val bigDecimal: BigDecimal = 60.5

  }

  def booleans(): Unit = {
    val trueValue: Boolean = true
    val falseValue: Boolean = false
  }

  def strings(): Unit = {
    val c: Char = 'c'
    val string: String = "This is some strings"

  }

  def declaration(): Unit = {
    //同时赋多个值
    val a, b = 100
    println(a, b)

    //常量和变量
    val immutable = 5
    var mutable = 15
    mutable = 16
  }
}
