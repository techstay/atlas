package tech.techstay.basic

import com.google.common.truth.Truth.assertThat

fun main() {
    try {
        val result = 1 / 0
    } catch (e: ArithmeticException) {
        e.printStackTrace()
    } finally {
        println("The finnaly block is always executed.")
    }

    // try is an expression
    val result: Int = try {
        "/".toInt()
    } catch (e: NumberFormatException) {
        0
    }
    assertThat(result).isEqualTo(0)
}
