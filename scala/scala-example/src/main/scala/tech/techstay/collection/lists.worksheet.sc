/* -------------------------------------------------------------------------- */
/*                                    Lists                                   */
/* -------------------------------------------------------------------------- */

// Create a list
List(1, 2, 3, 4, 5)
(1 to 5).toList
(1 until 5).toList
(1 to 10 by 2).toList
List.range(1, 5)
List.range(0, 100, 10)

// List operations
val list = List(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

list.head
list.tail
list.last
list.init
list.isEmpty
list.length
list.reverse
list.mkString(", ")
list.sorted

0 :: list
List(0, 0, 1) ::: list

// Stream operations

// Mapping
list.map(_ * 2)
List("one", "two").flatMap(_.toUpperCase)

// Filtering
list.filter(_ % 2 == 0)
List(List(1, 2), List(4, 3)).flatten
list.slice(2, 5)
list.take(5)
list.takeRight(5)
list.takeWhile(_ < 5)
list.drop(5)
list.dropRight(5)
list.dropWhile(_ < 5)

// Reducing and folding
list.reduce((acc, e) => acc + e)
list.fold(0)((acc, e) => acc + e * 2)
list.foldLeft(0)((acc, e) => acc + e * 2)
list.foldRight(0)((e, acc) => acc + e * 2)
list.zipWithIndex

// Zipping and unzipping
val zipped = list.zip(List("a", "b", "c", "d", "e"))
val unzipped = zipped.unzip

// Concatenation and splitting
val list1 = List(1, 2, 3)
val list2 = List(4, 5, 6)
val concatenated = list1 ++ list2
val splitAtIndex = concatenated.splitAt(3)

// Partitioning
val partitioned = list.partition(_ % 2 == 0)

// Grouping
val grouped = list.groupBy(_ % 2 == 0)

// Finding elements
list.find(_ > 5)
list.indexOf(5)
list.lastIndexOf(5)

// Checking membership
list.contains(5)
list.exists(_ == 5)

// Checking conditions
list.exists(_ > 5)
list.forall(_ < 5)
list.count(_ > 7)
