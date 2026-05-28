package tech.techstay.basic

import com.google.common.truth.Truth.assertThat

fun main() {
    // elvis operator
    val stringMaybeNull: String? = null
    assertThat(stringMaybeNull).isNull()
    assertThat(stringMaybeNull ?: "give me a value").isEqualTo("give me a value")
}
