package tech.techstay.coroutine

import com.google.common.truth.Truth.assertThat
import kotlinx.coroutines.*

fun main() = runBlocking {
    // cancelling delayed jobs
    var job = launch {
        repeat(100) {
            println("doing ${it + 1} ${if (it > 0) "times" else "time"}")
            delay(500)
        }
    }
    delay(2000)
    job.cancelAndJoin()
    println("the work has been cancelled.")

    val startTime = System.currentTimeMillis()
    var i = 0
    // cancelling computing jobs
    job = launch(Dispatchers.Default) {
        var nextTime = startTime
        while (isActive) {
            if (System.currentTimeMillis() >= nextTime) {
                println("doing ${i + 1} ${if (i > 0) "times" else "time"}")
                i++
                nextTime += 500L
            }

        }
    }
    delay(2000)
    job.cancelAndJoin()
    println("the work has been cancelled.")

    // timeout
    val result = withTimeoutOrNull(2000L) {
        repeat(100) {
            println("doing ${it + 1} ${if (it > 0) "times" else "time"}")
            delay(500)
        }
        "Done"
    }
    assertThat(result).isNull()
}
