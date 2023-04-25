package yitian.study.function

fun main(args: Array<String>) {
    doSomething("高阶函数", { e -> println(e) })
    doSomething("方法引用", ::println)

    //it是单个参数的别名
    //这里还是一个闭包，在lambda表达式中可以访问外层变量
    var sum: Int = 0
    (1..9).forEach { it -> sum += it }
    println("1 to 10 is $sum")


    val lambda = { a: String -> println(a) }
    lambda("lambda表达式")

    inlineFun({ println("内联函数") })

    //使用字符串构造器
    val str = buildString {
        for (i in 1..9) append("$i ")
        toString()
    }
    println("字符串构造结果是:$str")

    buildStringWithApply()


}

//高阶函数，参数是另一个函数或lambda表达式
fun doSomething(name: String, func: (e: String) -> Unit) {
    func(name)
}

//内联函数
inline fun inlineFun(func: () -> Unit) {
    func()
}

//String构造器
fun buildString(build: StringBuilder.() -> Unit): String {
    val sb = StringBuilder()
    sb.build()
    return sb.toString()
}

//使用apply简化String构造
fun buildStringWithApply() {
    val str = StringBuilder().apply {
        for (i in 1..9) append(i)
        toString()
    }
    println("字符串构造结果是:$str")
}

