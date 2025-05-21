/* -------------------------------------------------------------------------- */
/*                                 Collections                                */
/* -------------------------------------------------------------------------- */

import scala.collection.mutable.{ArrayBuffer, ListBuffer, Set}

val a = List(1, 2, 3, 4, 5)

// Commonly used operations
a.head
a.headOption
a.last
a.lastOption
a.tail
a.init
a.distinct
a.reverse
a.sorted

a.take(2)
a.takeRight(2)
a.takeWhile(_ < 4)
a.drop(2)
a.dropRight(2)
a.dropWhile(_ < 4)
a.slice(1, 4)

// Stream operations
a.filter(_ % 2 == 0)
a.filterNot(_ % 2 == 0)
a.map(_ * 2)
List(List(1, 2), List(3, 4)).flatten
a.foreach(println)

// Mapping
a.map(_ * 2)
List("one", "two").flatMap(_.toUpperCase)
List("one", "two").map(_.toUpperCase)

// Reducing and folding
a.reduce((acc, e) => acc + e)
a.reduce(_ + _)
a.fold(0)((acc, e) => acc + e * 2)
a.foldLeft(0)((acc, e) => acc + e * 2)
a.foldRight(0)((e, acc) => acc + e * 2)

// Aggregation
a.sum
a.product
a.min
a.max
a.minOption
a.maxOption

// Subdivisions
a.span(_ < 3)
a.partition(_ % 2 == 0)
a.groupBy(_ % 2)
a.groupMap(_ % 2)(_ * 2)

// Conditions
a.forall(_ <= 3)
a.exists(_ > 3)
a.count(_ % 2 != 0)

// Zipping and unzipping
val b = List("a", "b", "c", "d", "e")
val zipped = a.zip(b)
val unzipped = zipped.unzip
a.zipWithIndex
