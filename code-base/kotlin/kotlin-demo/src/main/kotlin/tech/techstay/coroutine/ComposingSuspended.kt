package tech.techstay.coroutine

import kotlinx.coroutines.async
import kotlinx.coroutines.delay
import kotlinx.coroutines.runBlocking
import kotlin.system.measureTimeMillis

suspend fun longWork1(): Int {
    delay(1000)
    return 21
}

suspend fun longWork2() = run {
    delay(1000)
    42
}

fun main() = runBlocking {
    // executing functions sequentially
    var time = measureTimeMillis {
        val result1 = longWork1()
        val result2 = longWork2()
        println("sum is ${result1 + result2}")
    }
    println("executing sequentially: $time ms")

    // executing functions concurrently
    time = measureTimeMillis {
        val result1 = async { longWork1() }
        val result2 = async { longWork2() }
        println("sum is ${result1.await() + result2.await()}")
    }
    println("executing concurrently: $time ms")
}
