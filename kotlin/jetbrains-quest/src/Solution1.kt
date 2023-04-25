package yitian.study

import kotlin.math.sqrt

// twitter https://twitter.com/jetbrains/status/1236986174075482113
fun twitterCode1() {
    val twitterCode =
        "48 61 76 65 20 79 6f 75 20 73 65 65 6e 20 74 68 65 20 73 6f 75 72 63 65 20 63 6f 64 65 20 6f 66 20 74 68 65 20 4a 65 74 42 72 61 69 6e 73 20 77 65 62 73 69 74 65 3f"
    val cipher = twitterCode.split(' ')
        .map { ch -> ch.toInt(16).toChar() }
        .joinToString(separator = "")
    println(cipher)
}

fun countPrimes(lowerBound: Int, upperBound: Int): Int {
    // 假设下标就是数本身，元素代表是否是素数
    val numbers = Array<Boolean>(upperBound + 1) { true }
    numbers[0] = false
    numbers[1] = false
    for (i in 2..(sqrt(upperBound.toDouble()).toInt() + 1)) {
        if (numbers[i]) {
            for (j in i * i..upperBound step i) {
                numbers[j] = false
            }
        }
    }
    return numbers.copyOfRange(lowerBound, upperBound)
        .count { it }
}

// Good luck! == Jrrg#oxfn$
fun printStringValue() {
    val string1 = "Good luck!"
    val string2 = "Jrrg#oxfn\$"
    println(string1.map { it.toInt().toString() }.joinToString(separator = " "))
    println(string2.map { it.toInt().toString() }.joinToString(separator = " "))
}

fun decryptCipher1() {
    val sss =
        "Qlfh\$#Li#|rx#duh#uhdglqj#wklv#|rx#pxvw#kdyh#zrunhg#rxw#krz#wr#ghfu|sw#lw1#Wklv#lv#rxu#lvvxh#wudfnhu#ghvljqhg#iru#djloh#whdpv1#Lw#lv#iuhh#iru#xs#wr#6#xvhuv#lq#Forxg#dqg#iru#43#xvhuv#lq#Vwdqgdorqh/#vr#li#|rx#zdqw#wr#jlyh#lw#d#jr#lq#|rxu#whdp#wkhq#zh#wrwdoo|#uhfrpphqg#lw1#|rx#kdyh#ilqlvkhg#wkh#iluvw#Txhvw/#qrz#lw“v#wlph#wr#uhghhp#|rxu#iluvw#sul}h1#Wkh#frgh#iru#wkh#iluvw#txhvw#lv#‟EhfdxvhFrgh†1#Jr#wr#wkh#Txhvw#Sdjh#dqg#xvh#wkh#frgh#wr#fodlp#|rxu#sul}h1#kwwsv=22zzz1mhweudlqv1frp2surpr2txhvw2"
    val cipher = sss.map { (it.toShort() - 3).toChar() }.joinToString(separator = "")
    println(cipher)
}

fun main() {
    twitterCode1()
    println("There are ${countPrimes(500, 5000)} primes between 500 to 5000")
    printStringValue()
    decryptCipher1()
}
