package tech.techstay.collection

import com.google.common.truth.Truth.assertThat

fun main() {
    // groupBy
    val numbers = listOf("one", "two", "three", "four", "five")
    val groups = numbers.groupBy { it.first() }
    println(groups)
    assertThat(groups).hasSize(3)

    // groupingBy
    val unmergedUsers = listOf(
        User("techstay", 6),
        User("zhang3", 8),
        User("li4", 2),
        User("techstay", 2),
        User("zhang3", 1),
        User("techstay", 10),
        User("li4", 2)
    )

    val mergedUsers = unmergedUsers.groupingBy { it.username }
        .fold(0) { acc, e -> acc + e.contributions }
        .map { entry -> User(entry.key, entry.value) }
        .sortedByDescending { it.contributions }

    assertThat(mergedUsers).isEqualTo(
        listOf(
            User("techstay", 18),
            User("zhang3", 9),
            User("li4", 4)
        )
    )
    println(mergedUsers)
}

data class User(val username: String, val contributions: Int)
