package tech.techstay.function

import com.google.common.truth.Truth.assertThat

// returning Unit
fun emptyFunction(): Unit {}

// single expression functions
fun singleExpressionFunction(string: String) = println("in fun2: $string")
fun someParamsFunction(a: Int = 0, b: String = "default", c: Boolean = false) {
    println("in fun3: $a $b $c")
}

// varargs functions
fun varargsFunction(vararg args: String) = args.joinToString(separator = " ", prefix = "")

// infix functions
infix fun Int.infixEqual(i: Int) = this == i

// tailrec functions
tailrec fun tailrecFactorial(n: Int, result: Int = 1): Int {
    return if (n == 0 || n == 1) result else tailrecFactorial(n - 1, n * result)
}

fun main() {
    // no returning means returning Unit
    emptyFunction()
    // one argument
    singleExpressionFunction("abc")
    // default arguments
    someParamsFunction()
    // specifying other arguments
    someParamsFunction(1, "666", true)
    // named arguments
    someParamsFunction(c = true, b = "oh my god", a = 42)

    assertThat(varargsFunction("a")).isEqualTo("a")
    assertThat(varargsFunction("a", "b", "c", "ddd")).isEqualTo("a b c ddd")

    // if the argument isn't a typed array, you should convert it
    // by calling toTypedArray() function
    val strings = arrayOf("a", "b", "c", "ddd")
    assertThat(varargsFunction(*strings)).isEqualTo("a b c ddd")

    // calling infix functions
    assertThat(1 infixEqual 6).isFalse()

    // tailrec function to calculate factorials
    println("factorial: ${tailrecFactorial(5)}")
}
