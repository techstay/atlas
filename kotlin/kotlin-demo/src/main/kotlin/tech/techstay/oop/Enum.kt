package tech.techstay.oop

import com.google.common.truth.Truth.assertThat

interface INext<T> {
    fun next(): T
}

enum class TrafficLight : INext<TrafficLight> {
    RED {
        override fun next() = YELLOW
    },
    YELLOW {
        override fun next() = GREEN
    },
    GREEN {
        override fun next() = RED
    },
}

fun main() {
    var light = TrafficLight.GREEN
    (1..5).forEach { _ ->
        println(light)
        light = light.next()
    }

    println(
        when (light) {
            TrafficLight.GREEN -> "green"
            TrafficLight.YELLOW -> "yellow"
            TrafficLight.RED -> "red"
        }
    )

    // converting between enums and strings
    assertThat(TrafficLight.GREEN.toString()).isEqualTo("GREEN")
    assertThat(TrafficLight.valueOf("RED")).isEqualTo(TrafficLight.RED)
}
