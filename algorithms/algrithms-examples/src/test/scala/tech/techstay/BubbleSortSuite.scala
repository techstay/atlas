package tech.techstay

import tech.techstay.sorting.BubbleSort
import scala.util.Random
import scala.math.Ordering.Int

class BubbleSortSuite extends munit.FunSuite:
  given Ordering[Int] = Ordering.Int

  test("BubbleSort.ascending") {
    val list = List(3, 1, 4, 1, 5, 9, 2, 6)
    val sorted = BubbleSort.sort(list)
    assert(sorted == List(1, 1, 2, 3, 4, 5, 6, 9))
  }

  test("BubbleSort.descending") {
    val list = List(3, 1, 4, 1, 5, 9, 2, 6)
    val sorted = BubbleSort.sort(list).reverse
    assert(sorted == List(9, 6, 5, 4, 3, 2, 1, 1))
  }

  test("BubbleSort.emptyList") {
    assert(BubbleSort.sort(Nil: List[Int]) == Nil)
    assert(BubbleSort.sort(Nil: List[Int]).reverse == Nil)
  }

  test("BubbleSort.singleElement") {
    assert(BubbleSort.sort(List(1)) == List(1))
    assert(BubbleSort.sort(List(1)).reverse == List(1))
  }

  test("BubbleSort.randomList") {
    val randomList = Random.shuffle((1 to 100).toList)
    val ascSorted = BubbleSort.sort(randomList)
    val descSorted = BubbleSort.sort(randomList).reverse

    assert(ascSorted == (1 to 100).toList)
    assert(descSorted == (100 to 1 by -1).toList)
  }

end BubbleSortSuite
