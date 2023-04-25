package yitian.study.function

fun main(args: Array<String>) {
    topLevelFun()
    println("5的阶乘是${factorial1(5)}")
    println("5的阶乘是${factorial2(5)}")
    println("5的阶乘是${factorial3(5)}")

    //普通调用
    "a".fuck("b")
    //中缀调用
    "a" fuck "b"

    //默认参数函数调用
    withDefaultParams()
    //命名参数调用
    withDefaultParams(i = 100, s = "123")

    singleExpr(1, 2)

    varargFun(1, 2, 3, 4)
}

//没有定义在类中的函数是顶层函数
fun topLevelFun() {
    println("这是一个顶层函数")
}

//迭代求阶乘
fun factorial1(n: Int): Int {
    return (1..n).reduce { a, b -> a * b }
    //return (1..n).fold(1, { a, b -> a * b })
}

//递归求阶乘
fun factorial2(n: Int): Int {
    return if (n == 0 || n == 1)
        1 else
        n * factorial2(n - 1)
}

//尾递归求阶乘,函数的最后一个表达式必须是递归函数本身
tailrec fun factorial3(n: Int, a: Int = 1): Int {
    return if (n == 0 || n == 1)
        a else factorial3(n - 1, n * a)
}

//中缀函数，可以作为中缀表达式使用
infix fun String.fuck(other: String) {
    println("$this fucks $other")
}

//默认参数
fun withDefaultParams(i: Int = 5, s: String = "default") {
    println("i=$i ,s=$s")
}

//单表达式函数
fun singleExpr(a: Int, b: Int) = println("a+b=${a + b}")

//可变参数函数
fun varargFun(vararg args: Int) {
    println(args.joinToString(prefix = "[", postfix = "]"))
}