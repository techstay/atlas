package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    val list = (1..10).toList()

    // aggregating
    assertThat(list.sum()).isEqualTo(55)
    assertThat(list.average()).isEqualTo(5.5)
    assertThat(list.max()).isEqualTo(10)
    assertThat(list.min()).isEqualTo(1)
    assertThat(list.count()).isEqualTo(10)
    assertThat(emptyList<Int>().minOrNull()).isNull()

    // fold function needs an initial value
    var sum = list.fold(0) { acc, i -> acc + i }
    assertThat(sum).isEqualTo(55)
    // reduce function uses the first two elements
    // to calculate the accumulate value
    sum = list.reduce { acc, i -> acc + i }
    assertThat(sum).isEqualTo(55)
}
