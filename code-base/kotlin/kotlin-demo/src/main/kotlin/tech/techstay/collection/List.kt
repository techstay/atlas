package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    val list = (1..10).toMutableList()
    // get
    assertThat(list[3]).isEqualTo(4)
    assertThat(list.get(3)).isEqualTo(4)
    assertThat(list.getOrElse(100) { it }).isEqualTo(100)
    assertThat(list.getOrNull(100)).isNull()

    // sub list
    assertThat(list.subList(3, 6)).isEqualTo(listOf(4, 5, 6))

    // indexOf
    assertThat(list.indexOf(1)).isEqualTo(0)
    assertThat(list.lastIndexOf(5)).isEqualTo(4)
    assertThat(list.indexOf(100)).isEqualTo(-1)
    assertThat(list.indexOfFirst { it % 2 == 0 }).isEqualTo(1)
    assertThat(list.indexOfLast { it % 4 == 0 }).isEqualTo(7)

    // binarySearch
    assertThat(list.binarySearch(4)).isEqualTo(3)
    assertThat(list.binarySearch(11)).isEqualTo(-11)

    // removing at
    list.removeAt(0)
    assertThat(list.first()).isEqualTo(2)

    // fill
    list.fill(100)
    assertThat(list.all { it == 100 }).isTrue()
}
