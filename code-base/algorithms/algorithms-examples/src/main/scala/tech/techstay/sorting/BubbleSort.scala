package tech.techstay.sorting

object BubbleSort:
  def sort[A](list: List[A])(using ord: Ordering[A]): List[A] =
    val arr = list.toBuffer
    val n = arr.length
    for i <- 0 until n do
      for j <- 0 until n - i - 1 do
        if ord.gt(arr(j), arr(j + 1)) then
          val tmp = arr(j)
          arr(j) = arr(j + 1)
          arr(j + 1) = tmp
    arr.toList
