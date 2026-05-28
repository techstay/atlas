package tech.techstay.function

import com.google.common.truth.Truth.assertThat
import kotlin.random.Random

fun main() {
    // let, context obj -> it, return -> lambda result
    val list1 = listOf(1, 2, 3)
    val list2 = listOf(2, 3, 4)
    (list1 union list2).map { it * it }
        .let {
            assertThat(it).hasSize(4)
            println(it)
        }

    // with, context obj -> this, return -> lambda result
    with(list1) {
        println("first: ${this.first()}")
        println("last: ${this.last()}")
    }

    // run, context obj -> this, return -> lambda result
    // implemented as extension functions, not likely with
    list1.run {
        println("the sum of the first and last elements: ${this.first() + this.last()}")
    }

    // apply, context obj -> this, return -> the obj itself
    var person = Person().apply {
        name = "techstay"
        age = 18
    }
    println(person)

    // also, context obj -> it, return -> the obj itself
    person = Person().also {
        it.name = "zhang3"
        it.age = 16
    }
    println(person)

    // takeIf and takeUnless
    var number = Random.nextInt(100)
    val isEvenOrNull = number.takeIf { it % 2 == 0 }
    val isOddOrNull = number.takeUnless { it % 2 == 0 }
    println(isEvenOrNull)
    println(isOddOrNull)
}

data class Person(val id: Int, var name: String, var age: Int) {

    constructor(name: String = "", age: Int = 0) : this(++ID_COUNT, name, age)

    companion object {
        private var ID_COUNT = 0
    }
}
