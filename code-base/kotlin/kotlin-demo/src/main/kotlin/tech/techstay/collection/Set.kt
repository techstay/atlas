package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    val set1 = setOf(1, 2, 3, 4)
    val set2 = setOf(3, 4, 5, 6)

    assertThat(set1 union set2).hasSize(6)
    assertThat(set1 intersect set2).isEqualTo(setOf(3, 4))
    assertThat(set1 subtract set2).isEqualTo(setOf(1, 2))
}
