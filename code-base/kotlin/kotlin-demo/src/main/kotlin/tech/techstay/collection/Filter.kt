package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    val list = (1..5).toList()
    // filter
    assertThat(list.filter { it % 2 == 0 }).isEqualTo(listOf(2, 4))
    assertThat(list.filterNot { it % 2 == 0 }).isEqualTo(listOf(1, 3, 5))
    assertThat(listOf(1, 2, "string", null).filterIsInstance<Int>()).isEqualTo(listOf(1, 2))
    assertThat(listOf(1, 2, "string", null).filterNotNull()).isEqualTo(listOf(1, 2, "string"))

    // partition
    val (even, odd) = list.partition { it % 2 == 0 }
    assertThat(even).isEqualTo(listOf(2, 4))
    assertThat(odd).isEqualTo(listOf(1, 3, 5))

    // test predicates
    assertThat(list.all { it > 0 }).isTrue()
    assertThat(list.any { it <= 1 }).isTrue()
    assertThat(list.none { it < 5 }).isFalse()
}
