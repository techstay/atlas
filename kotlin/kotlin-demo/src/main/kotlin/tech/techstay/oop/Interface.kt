package tech.techstay.oop

interface MyInterface {
    fun foo()
    fun bar(name: String): String
}

class MyImplements : MyInterface {
    override fun foo() {
        println("implemented foo")
    }

    override fun bar(name: String): String {
        println("implemented bar")
        return name.uppercase()
    }

}

fun main() {
    val obj = MyImplements()
    obj.foo()
    println(obj.bar("techstay"))
}
