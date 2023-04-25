package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    // slicing
    val numbers = (1..10).toList()
    assertThat(numbers.slice(1..3)).isEqualTo(listOf(2, 3, 4))
    assertThat(numbers.slice(listOf(1, 3, 5))).isEqualTo(listOf(2, 4, 6))

    // taking
    assertThat(numbers.take(3)).isEqualTo(listOf(1, 2, 3))
    assertThat(numbers.takeLast(3)).isEqualTo(listOf(8, 9, 10))
    assertThat(numbers.takeWhile { it < 5 }).isEqualTo((1..4).toList())
    assertThat(numbers.takeLastWhile { it >= 5 }).isEqualTo((5..10).toList())

    // dropping
    assertThat(numbers.drop(3)).isEqualTo((4..10).toList())
    assertThat(numbers.dropLast(3)).isEqualTo((1..7).toList())
    assertThat(numbers.dropWhile { it < 5 }).isEqualTo((5..10).toList())
    assertThat(numbers.dropLastWhile { it >= 5 }).isEqualTo((1..4).toList())

    // chunked
    assertThat(numbers.chunked(3)).hasSize(4)
    assertThat(numbers.chunked(3) { it.count() }).isEqualTo(listOf(3, 3, 3, 1))

    // windowed
    assertThat(listOf(1, 2, 3).windowed(2)).isEqualTo(listOf(listOf(1, 2), listOf(2, 3)))
    assertThat(numbers.windowed(4)).hasSize(7)
    assertThat(numbers.windowed(4, step = 2)).hasSize(4)
    assertThat(numbers.windowed(4, partialWindows = true)).hasSize(10)
    // use zipWithNext to create 2-elements window
    assertThat(listOf(1, 2, 3, 4).zipWithNext())
        .isEqualTo(listOf(Pair(1, 2), Pair(2, 3), Pair(3, 4)))

}
