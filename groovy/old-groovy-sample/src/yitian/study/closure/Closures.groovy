package yitian.study.closure

import java.time.LocalDate
import java.time.LocalTime


class Closures {
    static void main(String[] args) {
        simpleClosure()
        funWithClosure { println("Hello yitian") }
        closureInGString()
        fibonacci()
        factorial()
    }

    static void simpleClosure() {
        def fun = { println("$it") }
        fun(1234)

        Closure date = { println(LocalDate.now()) }
        date.call()

        Closure<LocalTime> time = { LocalTime.now() }
        println("now is ${time()}")
    }

    //将GString中的表达式声明为闭包
    static void closureInGString() {
        def x = 5
        def str = "x=${-> x}"
        println(str)

        x = 6
        println(str)
    }
    //闭包作为参数
    static void funWithClosure(Closure closure) {
        closure()
    }

    static void fibonacci() {
        def fib
        fib = { long n -> n < 2 ? n : fib(n - 1) + fib(n - 2) }.memoize()
        println("fibonaci:${fib(35)}")
    }

    static void factorial() {
        def factorial
        factorial = { int n, accu = 1G ->
            if (n < 2) return accu
            factorial.trampoline(n - 1, n * accu)
        }
        factorial = factorial.trampoline()
        println("factorial:${factorial(1000)}")
    }
}
