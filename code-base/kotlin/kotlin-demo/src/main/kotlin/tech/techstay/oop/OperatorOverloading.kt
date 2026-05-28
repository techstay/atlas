package tech.techstay.oop

import com.google.common.truth.Truth.assertThat

fun main() {
    assertThat(MyValue(1) + MyValue(2)).isEqualTo(MyValue(3))
    assertThat(MyValue(2) * MyValue(3)).isEqualTo(MyValue(6))
    println(MyValue(2) * MyValue(100))
}

data class MyValue(val value: Double) {
    constructor(value: Int) : this(value.toDouble())

    operator fun plus(other: MyValue) = MyValue(value + other.value)
}

operator fun MyValue.times(other: MyValue): MyValue = MyValue(this.value * other.value)
