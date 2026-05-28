/* -------------------------------------------------------------------------- */
/*                              Immutable Arrays                              */
/* -------------------------------------------------------------------------- */

// Creating Vectors
Vector(1, 2, 3, 4, 5)
Vector.range(1, 6)

/* -------------------------------------------------------------------------- */
/*                               Mutable Arrays                               */
/* -------------------------------------------------------------------------- */
import scala.collection.mutable.ArrayBuffer

// Creating mutable arrays
ArrayBuffer[Int]()
ArrayBuffer[Int](10)
ArrayBuffer(1, 2, 3, 4, 5)
ArrayBuffer.range(1, 6)
ArrayBuffer.fill(5)(0)
ArrayBuffer.tabulate(5)(i => i * 2)

// Adding elements
val ab = ArrayBuffer(1, 2)
ab += 3
ab ++= ArrayBuffer(4, 5)
ab.append(6)
ab.prepend(0)

// Inserting elements
ab.insert(2, 99)
ab

ab.insertAll(1, ArrayBuffer(10, 11))
ab

// Removing elements
ab -= 99
ab --= ArrayBuffer(4, 5)
ab.remove(2) // removes element at index 2
ab

// Removing a range of elements
ab.remove(1, 2) // removes 2 elements starting from index 1
ab

// Accessing elements
ab(0) // first element
ab.last // last element
ab.head // first element
ab.tail // all elements except the first
ab.init // all elements except the last
ab.indices // indices of the array
ab.length // number of elements
ab.isEmpty // checks if the array is empty

// Updating elements
ab(0) = 100 // update first element
ab
ab.update(1, 200) // update element at index 1
ab
