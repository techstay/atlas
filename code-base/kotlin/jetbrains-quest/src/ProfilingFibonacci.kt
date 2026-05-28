package yitian.study

import java.math.BigInteger
import java.time.Duration
import java.time.LocalDateTime

// 循环求解
fun fibonacci1(n: Int): BigInteger {
    if (n <= 1) {
        return BigInteger.valueOf(n.toLong())
    }

    var a = BigInteger.ZERO
    var b = BigInteger.ONE
    var t: BigInteger
    for (i in 2..n) {
        t = a
        a = b
        b += t
    }
    return b
}

// https://www.maplesoft.com/applications/download.aspx?SF=154362/fibonaccinumbers.pdf
// duplication formula
// f(2n)  = f(n)^2 + 2f(n-1)f(n)
// f(2n-1)= f(n)^2 + f(n-1)^2
fun fibonacci2(n: Int, cache: HashMap<Int, BigInteger>): BigInteger {
    if (n <= 1) {
        return BigInteger.valueOf(n.toLong())
    }

    return if (n % 2 == 0) {
        val b = cache.getOrPut(n / 2, { fibonacci2(n / 2, cache) })
        val a = cache.getOrPut(n / 2 - 1, { fibonacci2(n / 2 - 1, cache) })
        b * b + BigInteger.TWO * b * a
    } else {
        val b = cache.getOrPut((n + 1) / 2, { fibonacci2((n + 1) / 2, cache) })
        val a = cache.getOrPut((n - 1) / 2, { fibonacci2((n - 1) / 2, cache) })
        a * a + b * b
    }

}

fun main() {
    val profile = fun(task: () -> Unit) {
        val t1 = LocalDateTime.now()
        task()
        val t2 = LocalDateTime.now()
        println(Duration.between(t1, t2))
    }
    val c = HashMap<Int, BigInteger>()
    val n = 5e7.toInt()
    //profile { println(fibonacci1(n)) }
    profile { println(fibonacci2(n, c)) }
}