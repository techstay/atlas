package tech.techstay.collection

fun main() {
    // using iterators
    val list = intArrayOf(1, 2, 3, 4, 5)
    val iterator: IntIterator = list.iterator()
    while (iterator.hasNext()) {
        print("${iterator.next()} ")
    }
    println()
    // equivalent to foreach iterations
    for (i in list) {
        print("$i ")
    }
    println()
    // or foreach closures
    list.forEach { print("$it ") }
    println()

    // custom iterators
    val myList = MyList(1, 2, 3, 4, 5)
    for (i in myList) {
        print("$i ")
    }
    println()
}

// collections should implement Iterable interface
class MyList(private vararg val elements: Int) : Iterable<Int> {
    // should return an Iterator object
    override fun iterator(): Iterator<Int> {
        // the Iterator should implement next and hasNext methods
        return object : Iterator<Int> {
            var current = 0
            override fun hasNext(): Boolean = current < elements.size

            override fun next(): Int {
                if (!hasNext()) throw NoSuchElementException()
                return elements[current++]
            }
        }
    }
}
