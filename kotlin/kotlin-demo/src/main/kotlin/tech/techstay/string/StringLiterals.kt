package tech.techstay.string

fun main() {
    // strings are all immutable
    val escapedString = "hello world!\n"
    val rawString = """
        some line
        all characters are reserved
    """.trimIndent()

    println(escapedString)
    println(rawString)
}
