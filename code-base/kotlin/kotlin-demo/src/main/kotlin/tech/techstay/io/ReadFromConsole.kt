package tech.techstay.io

fun main() {
    println("type exit or quit to terminate.")
    do {
        val input = readln()
        println("you just typed: $input")
    } while (input.lowercase() !in setOf("exit", "quit"))

}
