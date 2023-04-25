package yitian.study.basic

import scala.collection.mutable

/**
  * 集合操作
  */
object Collections {
  def main(args: Array[String]): Unit = {
    lists()
    iterators()
    sets()
    maps()
    tuples()
  }

  def lists(): Unit = {
    var list1 = List(1, 2, 3, 4, 5)
    var list2 = List[String]("hello", ",", "leo")
    var emptyList = List[Int]()

    println(list1)
    println(list2)

    println(list1.isEmpty)
    println(emptyList.isEmpty)

    //连接列表
    println(list1 ::: list2)

    var list3 = List.tabulate(5)(n => (n + 1) * (n + 1))
    println(list3)
  }

  def sets(): Unit = {
    //不可变集合
    val immutableSet = Set(1, 2, 3, 4, 5, 2, 3, 1)
    println(immutableSet)

    val set2 = mutable.Set(9, 8)
    set2.add(7)
    set2.add(6)
    println(set2.min)
    println(set2.max)
    println(immutableSet & set2)

  }

  def maps(): Unit = {
    var map1 = mutable.Map[Int, Int](1 -> 1, 2 -> 2, 3 -> 3)
    map1 += (4 -> 4)
    println(map1)

    map1(4) = 5
    println(map1)
  }

  def tuples(): Unit = {
    val tuple1 = (1, 2, 3, "Yitian")
    println(tuple1)

    val (i1, i2, i3, name) = tuple1
    println(i1, i2, i3, name)

  }

  def iterators(): Unit = {
    val iter1 = Iterator(1, 2, 3, 4, 5)

    while (iter1.hasNext) {
      print(iter1.next())
    }
    println()


  }
}
