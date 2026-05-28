package tech.techstay.basic

fun main() {
    // if statement
    val a = 1
    val b = 2
    if (a <= b) {
        println("$a <= $b")
    } else {
        println("$a > $b")
    }

    // if expression
    val greater = if (a > b) a else b
    val less = if (a < b) {
        a
    } else {
        b
    }
}
