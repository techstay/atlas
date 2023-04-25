package yitian.study.basic

/**
  * Scala 基本运算符
  */
object Operators {
  def main(args: Array[String]): Unit = {
    arithmeticalOperators()
    relationalOperators()
    logicalOperators()
    bitwiseOperators()
  }

  def arithmeticalOperators(): Unit = {
    var result = 10 + 20.5
    result = 10 - 43
    result = 10 * 200
    result = 100 / 5
    result = 107 % 9
  }

  def relationalOperators(): Unit = {
    var result = 1 > 2
    result = 1 < 2
    result = 1 <= 2
    result = 1 >= 2
    result = 1 == 2
    result = 1 != 2

  }

  def logicalOperators(): Unit = {
    var result = true && false
    result = true || false
    result = !true

  }

  def bitwiseOperators(): Unit = {
    var result = 4 & 3
    result = 7 | 8
    result = 3 ^ 4
    result = ~2
    result = 4 >> 2
    result = 4 << 2
    result = -4 >>> 3
  }
}
