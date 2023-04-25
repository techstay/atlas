package yitian.study.basic

import Array._

/**
  * 数组
  */
object Arrays {
  def main(args: Array[String]): Unit = {
    newArray()
    iterateArray()
    matrixArray()
    rangeArray()
  }

  /**
    * 数组的创建
    */
  def newArray(): Unit = {
    val array1 = new Array[Int](4)
    array1(2) = 3
    println(array1(2))

    val array2 = Array(2, 3, 4, 5)
    println(array2)


  }

  def iterateArray(): Unit = {
    val array = Array(12, 3, 4, 5, 6, 7)
    for (i <- array) {
      print(i + ", ")
    }
    println()
  }

  /**
    * 多维数组
    */
  def matrixArray(): Unit = {
    val matrix = ofDim[Int](3, 3)

    for (i <- 0 until 3) {
      for (j <- 0 until 3) {
        print(matrix(i)(j) + ", ")
      }
      println()
    }

  }

  /**
    * 区间数组
    */

  def rangeArray(): Unit = {
    val array = range(1, 10, 2)
    for (i <- array) {
      print(i)
    }
    println()
  }
}

