package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    val list = mutableListOf(1, 2, 3, 4, 5)

    // adding
    list.add(1)
    list.addAll(listOf(1, 2, 3))
    list += 6
    list += listOf(6, 6, 6)
    assertThat(list).hasSize(13)

    // removing given value, do nothing if no element found
    list.remove(4)
    list.remove(4)
    assertThat(list).hasSize(12)


    // removing all
    list.removeAll(listOf(1, 2, 3))
    assertThat(list).isEqualTo(listOf(5, 6, 6, 6, 6))

    // clear
    list.clear()
    assertThat(list).isEmpty()

}
