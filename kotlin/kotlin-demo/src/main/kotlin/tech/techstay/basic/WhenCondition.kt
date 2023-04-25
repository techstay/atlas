package tech.techstay.basic

fun main() {
    val level = 's'
    println(
        when (level) {
            'c' -> "bad"
            'b' -> "not bad"
            'a' -> "good"
            's' -> "excellent"
            else -> "not defined"
        }
    )

    val number = 60
    println(
        when (number) {
            in (0 until 60) -> "failed"
            else -> "pass"
        }
    )
}
