package tech.techstay.basic

fun main() {
    // while
    var i = 0
    while (i <= 10) {
        print("$i ")
        i++
    }
    println()

    i = 0
    do {
        print("$i ")
    } while (i++ <= 10)
    println()
}
