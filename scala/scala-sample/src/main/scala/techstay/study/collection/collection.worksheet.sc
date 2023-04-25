import scala.collection.mutable.{ArrayBuffer, ListBuffer, Set}

// ranges
val numbers1 = (1 to 10).toVector
val numbers2 = (1 until 10).toVector
val odd = (1 to 10 by 2).toVector

// immutable arrays
val v = Vector(1, 2, 3, 4, 5)
println(s"the second element of v: ${v(1)}")
v.foreach(e => print(s"$e "))
println()

// mutable arrays
val array = ArrayBuffer(1, 2, 3, 4)
println(array)
array += 5
array ++= List(6, 7, 8)
println(array)
array(1) = 200
array.update(5, 600)
println(array)

// immutable linked-list
val list = List(1, 2, 3, 4)
println(list)
println(list(2))
list.foreach(e => print(s"$e "))
println()

// mutable linked-list
val listBuffer = ListBuffer(1, 2, 3, 4)
listBuffer += 5
listBuffer ++= List(6, 7)
listBuffer(3) = 300
println(listBuffer)

// mutable set
val set1 = Set(1, 2, 3, 4, 8)
val set2 = Set(2, 3, 5)
// adding elements
set1.add(3)
set2.add(6)
// deleting elements
set1.remove(8)
// set operations
println(s"set1: $set1")
println(s"set2: $set2")
println(set1 intersect set2)
println(set1 union set2)
println(set1 diff set2)

// immutable map
val m = Map[Int, String](1 -> "one", 2 -> "two", 3 -> "three")
println(m)
for (k, v) <- m do println((k, v))
println(s"the value for key 2: ${m(2)}")

// mutable map
val map = scala.collection.mutable.Map(1 -> "one", 2 -> "two")
map.update(3, "three")
map.remove(2)
println(map)
println(s"get value: ${map.getOrElse(2, "TWO")}")

// stream operations
val numbers = Vector.range(1, 10 + 1)
// mapping
numbers.map(_ * 2)

// first and last
numbers.head
numbers.last
// init and tai
numbers.init
numbers.tail
// taking
numbers.take(2)
numbers.takeRight(2)
numbers.takeWhile(_ < 5)
// dropping
numbers.drop(3)
numbers.dropRight(3)
numbers.dropWhile(_ > 3)
// filtering
numbers.filter(e => e > 5)
// reducing
numbers.reduce((acc, e) => acc + e)
// folding
numbers.fold(0)((acc, e) => acc + e * 2)
