package tech.techstay.oop

import com.google.common.truth.Truth.assertThat

// extension methods
fun String.hello(): String {
    val greeting = "hello $this"
    println(greeting)
    return greeting
}

// extension properties
val String.tellMeTheUpperCase: String
    get() = this.uppercase()

fun main() {
    assertThat("techstay".hello()).isEqualTo("hello techstay")
    assertThat("techstay".tellMeTheUpperCase).isEqualTo("TECHSTAY")
}
