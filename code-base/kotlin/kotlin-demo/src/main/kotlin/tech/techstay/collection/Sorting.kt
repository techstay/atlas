package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    val list = listOf(4, 4, 3, 6, 1)
    val people = listOf(
        MyPerson(1, "techstay", 18),
        MyPerson(2, "zhang3", 16),
        MyPerson(3, "li4", 25),
        MyPerson(4, "wang5", 30)
    )
    // sorted
    assertThat(list.sorted()).isEqualTo(listOf(1, 3, 4, 4, 6))
    assertThat(list.sortedDescending()).isEqualTo(listOf(6, 4, 4, 3, 1))

    // sorted with
    assertThat(people.sortedWith(compareBy { it.age }).first()).isEqualTo(people[1])
    assertThat(people.sortedWith(compareBy<MyPerson> { it.id }.thenBy { it.name }).first())
        .isEqualTo(people[0])


    // reversed
    assertThat(list.reversed()).isEqualTo(listOf(1, 6, 3, 4, 4))
    // asReversed returns a view that may change corresponding to the original collection
    assertThat(list.asReversed()).isEqualTo(listOf(1, 6, 3, 4, 4))

    // sorted by
    assertThat(people.sortedBy { it.id }.first()).isEqualTo(people[0])
    assertThat(people.sortedByDescending { it.name }.first()).isEqualTo(people[1])

    // shuffle
    assertThat(list.shuffled()).hasSize(list.size)
}

data class MyPerson(val id: Int, val name: String, val age: Int)
