package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    val array = arrayOf(1, 2, 3)

    // mapping
    assertThat(array.map { it * it }).isEqualTo(listOf(1, 4, 9))
    assertThat(array.mapIndexed { index, e -> index * e }).isEqualTo(listOf(0, 2, 6))

    // zipping
    val array1 = arrayOf(1, 2, 3)
    val array2 = arrayOf(4, 5, 5, 1, 2, 3)
    val zipped = array1 zip array2
    assertThat(zipped).isEqualTo(listOf(Pair(1, 4), Pair(2, 5), Pair(3, 5)))

    // unzipping
    val (unzipped1, unzipped2) = zipped.unzip()
    assertThat(unzipped1).isEqualTo(listOf(1, 2, 3))
    assertThat(unzipped2).isEqualTo(listOf(4, 5, 5))

    // associating, building the map
    assertThat(array.associateWith { it * it }).isEqualTo(mapOf(1 to 1, 2 to 4, 3 to 9))
    assertThat(array.associateBy { it * it }).isEqualTo(mapOf(1 to 1, 4 to 2, 9 to 3))
    assertThat(array.associate { it * it to it * it * it }).isEqualTo(mapOf(1 to 1, 4 to 8, 9 to 27))

    // flattening
    val twoDimensionArray = arrayOf(arrayOf(1, 2), arrayOf(2, 2), arrayOf(3, 3))
    assertThat(twoDimensionArray.flatten()).isEqualTo(listOf(1, 2, 2, 2, 3, 3))
    data class MyValues(val values: List<Int>)

    val myValuesList = listOf<MyValues>(
        MyValues(listOf(1, 2, 3)), MyValues(listOf(2, 2, 2)), MyValues(listOf(3, 3, 3))
    )
    assertThat(myValuesList.flatMap { it.values }).isEqualTo(listOf(1, 2, 3, 2, 2, 2, 3, 3, 3))

    // joining
    assertThat(array.joinToString(prefix = "{{", postfix = "}}", separator = ", "))
        .isEqualTo("{{1, 2, 3}}")
}
