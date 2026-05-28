package tech.techstay.function

import com.google.common.truth.Truth.assertThat

fun main() {

    // high-order functions are functions that take functions
    // as parameters, or return functions
    val numbers = listOf(1, 2, 3, 4, 5)
    val result = numbers.fold(0) { acc, n -> acc + n }
    assertThat(result).isEqualTo(15)

    // lambda expressions
    val sum = { a: Int, b: Int -> a + b }
    assertThat(sum(3, 2)).isEqualTo(5)

    // implicit parameter: it
    val lengthOfString: (String) -> Int = { it.length }
    assertThat(lengthOfString("555")).isEqualTo(3)

    // underscore for unused variables
    val getEmptyString: (String) -> String = { _ -> "" }
    assertThat(getEmptyString("")).isEmpty()

    // anonymous functions
    val sum2 = fun(a: Int, b: Int): Int = a + b
    assertThat(sum2(3, 3)).isEqualTo(6)

    // invoking functions
    assertThat(sum.invoke(3, 2)).isEqualTo(5)
}
