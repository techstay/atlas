package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    // getting the specific elements
    val list = listOf(1, 2, 3, 4, 5)
    assertThat(list.elementAt(3)).isEqualTo(list[3])
    assertThat(list.elementAtOrNull(10)).isNull()
    assertThat(list.elementAtOrElse(10) { "$it not found" })
        .isEqualTo("10 not found")

    // first and last
    assertThat(list.first()).isEqualTo(1)
    assertThat(list.last()).isEqualTo(5)
    assertThat(list.first { it > 3 }).isEqualTo(4)
    assertThat(list.last { it < 3 }).isEqualTo(2)
    assertThat(list.firstOrNull { it > 10 }).isNull()
    assertThat(list.lastOrNull { it < 0 }).isNull()

    // find and findLast
    assertThat(list.find { it > 3 }).isEqualTo(4)
    assertThat(list.find { it > 10 }).isNull()
    assertThat(list.findLast { it < 3 }).isEqualTo(2)
    assertThat(list.findLast { it < 0 }).isNull()

    // mapping and getting first elements
    assertThat(list.firstNotNullOf { it * it }).isEqualTo(1)
    assertThat(emptyList<Int>().firstNotNullOfOrNull { it * it }).isNull()

    // getting random elements
    assertThat(list.random()).isIn(list)

    // checking elements existence
    assertThat(list.contains(2)).isTrue()
    assertThat(3 in list).isTrue()
    assertThat(list.containsAll(listOf(1, 2, 3))).isTrue()
    assertThat(list.isEmpty()).isFalse()
    assertThat(emptyList<Int>().isNotEmpty()).isFalse()
}
