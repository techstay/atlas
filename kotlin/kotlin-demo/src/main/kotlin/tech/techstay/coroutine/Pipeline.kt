package tech.techstay.coroutine

import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.channels.consumeEach
import kotlinx.coroutines.channels.produce
import kotlinx.coroutines.runBlocking

@OptIn(ExperimentalCoroutinesApi::class)
fun main() = runBlocking {
    val numberChannel = produce<Int> {
        repeat(10) {
            send(it + 1)
        }
    }

    numberChannel.consumeEach {
        print("$it ")
    }
    println()
}
