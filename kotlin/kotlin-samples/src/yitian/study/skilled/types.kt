package yitian.study.skilled

fun main(args: Array<String>) {
    typeCasts()
    smartCasts()
    typeCastOperators()
}

open class A
class B : A() {
    fun hello() {
        println("I'm B")
    }
}

class C

//使用is和!is判断对象类型
fun typeCasts() {
    val a: Any = A()
    val b: Any = B()
    val c: Any = C()
    println("a is A:${a is A}")
    println("b is A:${b is A}")
    println("c is A:${c is A}")
    println("c is not A:${c !is A}")
}

//智能转换，在is上下文霞，编译器知道具体类型，不需要额外转换
fun smartCasts() {
    val b: A = B()
    if (b is B) {
        b.hello()
    }
}

//类型转换符
fun typeCastOperators() {
    val b: Any = B()
    val c: Any = C()
    var unsafeA: A

    //成功转换
    unsafeA = b as A
    //转换失败，抛出异常
    try {
        unsafeA = c as A
    } catch (e: ClassCastException) {
        println(e.message)
    }

    var safeA: A?
    //成功转换
    safeA = b as A
    //转换失败
    safeA = c as? A
    println(safeA)
}

//类型缩写
typealias MyMap = HashMap<String, String>