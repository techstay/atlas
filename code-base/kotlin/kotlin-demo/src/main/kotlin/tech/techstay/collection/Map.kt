package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    val map = mutableMapOf(1 to 11, 2 to 223, 3 to 3334)

    // getting elements
    assertThat(map[1]).isEqualTo(11)
    assertThat(map.get(1)).isEqualTo(11)
    assertThat(map.get(5)).isNull()
    assertThat(map.getOrDefault(5, 666)).isEqualTo(666)
    assertThat(map.getOrElse(5, { 666 })).isEqualTo(666)

    // keys and values
    assertThat(map.keys).hasSize(3)
    assertThat(map.values).contains(223)

    // filter
    assertThat(
        map.filter { entry -> entry.key == 2 || entry.value.toString().startsWith("2") })
        .hasSize(1)
    assertThat(map.filterKeys { it > 1 }).hasSize(2)
    assertThat(map.filterValues { it < 2000 }).hasSize(2)

    // plus functions update the left operand map with the right operand
    assertThat(map + Pair(4, 2)).hasSize(4)
    assertThat(map + Pair(1, 100)).hasSize(3)
    // minus functions remove the entries with the right operand keys
    assertThat(map - listOf(1, 2, 3)).isEmpty()

    // put
    map.put(4, 444)
    map[5] = 5
    assertThat(map).hasSize(5)

    // removing elements
    map.remove(1)
    map.remove(2, 2)
    assertThat(map).hasSize(4)
    map.keys.remove(2)
    assertThat(map).hasSize(3)
    map.values.remove(3334)
    assertThat(map).hasSize(2)
}
