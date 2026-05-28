package tech.techstay.basic

fun main() {
    for (i in 1..10) {
        print("$i ")
    }
    println()

    val array = arrayOf(1, 2, 3, 4, 5)
    for (i in array.indices) {
        print("${array[i]} ")
    }
    println()

    for (i in 1 until 20 step 2) {
        print("$i ")
    }
    println()

    for (i in 20 downTo 1 step 2) {
        print("$i ")
    }
    println()

    // equivalent to repeat functions
    repeat(10) {
        print("$it ")
    }
    println()
}
