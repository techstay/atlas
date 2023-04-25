package yitian.study.oop

import java.time.LocalDate
import java.time.LocalDateTime
import kotlin.properties.Delegates

fun main(args: Array<String>) {
    val front = Front(Back())
    front.hi()

    //延迟加载
    val lazy = LazyClass("yitian")
    println("测试延迟加载:${lazy.value}")
    println("测试延迟加载:${lazy.value}")

    val myObserver = MyObserver("yitian")
    myObserver.name = "zhang3"
    myObserver.name = "li4"

    val student = Student(mapOf(
            "id" to 1,
            "name" to "yitian",
            "age" to 24,
            "birthday" to LocalDate.of(1994, 2, 3)))
    println("学生是:$student")

    localDelegates()
}

interface Hi {
    fun hi()
}

open class Back : Hi {
    override fun hi() = println("Say hi")
}

//将类代理到接口上，接口的所有属性都会自动实现
class Front(back: Back) : Hi by back

class LazyClass(value: String) {
    val value: String by lazy {
        println("首次调用")
        value
    }
}

//观察者模式
class MyObserver(name: String) {
    var name: String by Delegates.observable("默认值") {
        prop, old, new ->
        println("属性是:$prop 旧值是:$old 新值是:$new")
    }
}

//属性和Map转换
data class Student(val map: Map<String, Any?>) {
    val id: Int by map
    val name: String by map
    val age: Int by map
    val birthday: LocalDate by map
}

//本地委托
fun localDelegates() {
    val operation = {
        println("首次调用")
        "这是结果:${LocalDateTime.now()}"
    }
    val func by lazy(operation)
    println(func)
    println(func)
}