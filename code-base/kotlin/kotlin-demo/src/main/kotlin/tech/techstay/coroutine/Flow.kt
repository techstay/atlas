package tech.techstay.coroutine

import kotlinx.coroutines.delay
import kotlinx.coroutines.flow.collectLatest
import kotlinx.coroutines.flow.flow
import kotlinx.coroutines.flow.map
import kotlinx.coroutines.flow.take
import kotlinx.coroutines.runBlocking
import kotlin.system.measureTimeMillis

fun main() = runBlocking {
    var flow = flow {
        repeat(5) {
            delay(300)
            emit(it)
        }
    }

    flow.map { it * it }
        .take(3)
        .collect { value -> println(value) }

    // collecting the latest value
    // expected to be finished in 5 * 300 + 500 = 2000 ms
    val time = measureTimeMillis {
        flow.collectLatest { value ->
            println("collecting $value ...")
            delay(500)
            println("Done $value")
        }
    }
    println("collected in $time ms")

}
