package tech.techstay.coroutine

import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking

suspend fun main() = runBlocking {
    launch {
        delay(2000)
        println("Kotlin Coroutines World!")
    }
    println("Hello")
}
