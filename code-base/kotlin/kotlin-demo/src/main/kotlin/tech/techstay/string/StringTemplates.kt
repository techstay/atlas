package tech.techstay.string

fun main() {
    val name = "techstay"
    val greetings = "Hello, $name"
    val stop = "STOP! ${name.uppercase()}"

    println(greetings)
    println(stop)
}
