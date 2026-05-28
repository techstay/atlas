package tech.techstay.benchmark

import kotlin.time.ExperimentalTime
import kotlin.time.measureTimedValue

@OptIn(ExperimentalTime::class)
fun main() {
    val longWork = {
        repeat(2_000_000) {
            print(".")
        }
        println()
        "Done"
    }

    val (value, time) = measureTimedValue { longWork() }
    println("the task $value took $time.")
}
