package yitian.study

import java.math.BigInteger
import java.util.*
import kotlin.collections.HashMap

// https://twitter.com/jetbrains/status/1238420744817782784
fun twitterCode3() {
    val sss = "SGF2ZSB5b3Ugc2VlbiB0aGUgcG9zdCBvbiBvdXIgSW5zdGFncmFtIGFjY291bnQ/"
    println(Base64.getDecoder().decode(sss).map { it.toChar() }.joinToString(separator = ""))
}

fun tryDecrypt() {
    val tryFunc = fun(n: Int) {
        val s =
            "Zh#kdyh#ehhq#zrunlqj#552:#rq#wkh#ylghr#iru#wkh#iluvw#hslvrgh#ri#wkh#SksVwrup#HDS1#Li#zh#jdyh#|rx#d#foxh/#lw#zrxog#eh#hdv|#dv#sl1"
        for (c in s) {
            print(c - n)
        }
        println()
    }
    (1..3).forEach { tryFunc(it) }
}

fun printFirstLetters() {
    val ss =
        ". Not Everything Today Does All You Could Ask. Lessons Learned From Other Relevant Solutions, Possibly Even Another Kind Emerge. Risking Sometimes Being Liberal Or Generous Proves Ordinary Simple Tests Infinitely More Annoying. Get Examining Hidden Initial Designated Early Symbols. They Have Everything Needed, Except Xerox, To Completely Level Up Everything."
    println(ss.split(' ').map { it.first() }.joinToString(separator = ""))
}


fun main() {
    twitterCode3()
    tryDecrypt()
//    println((1..10).map { fibonacci(it) }.joinToString(separator = " "))
    printFirstLetters()
    // first 4 and last 4 digits of fibonacci(5e7)
    val fib5e7 = fibonacci2(5e7.toInt(), HashMap())
    val fib5e7s = fib5e7.toString()
    println(fib5e7s.substring(0, 4) + fib5e7s.substring(fib5e7s.length - 4, fib5e7s.length))
}
