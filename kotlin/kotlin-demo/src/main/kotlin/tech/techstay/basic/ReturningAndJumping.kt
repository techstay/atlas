package tech.techstay.basic

fun main() {
    outerLoop@ for (i in 1..100) {
        for (j in 1..100) {
            if (i == 1 && j == 1) {
                break@outerLoop
            }
            println(i * j)
        }
    }
    println("This is out of outerLoop")

    (1..100).forEach {
        if (it >= 2) {
            return@forEach
        }
        println(it)
    }
    println("This is out of lambda expressions")
}
