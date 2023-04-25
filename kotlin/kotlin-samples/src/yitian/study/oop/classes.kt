package yitian.study.oop

fun main(args: Array<String>) {

    //调用数据类
    val cuboid = Cuboid(3.0, 4.0, 5.0)
    println("cuboid=$cuboid")
}

//类声明和构造函数
class Class1(name: String, value: Int) {
    val name: String = name
    val value = value
    override fun toString(): String {
        return "(name=$name,value=$value"
    }

    //可见修饰符

    public fun f1() {}
    protected fun f2() {}
    private fun f3() {}
    internal fun f4() {}

}

//简便声明属性
class Product(
        var name: String,
        var customer: String,
        var price: Double) {

}


//抽象类
abstract class Girl(name: String) : Person(name) {
    abstract fun dress()

    //自定义属性
    var favoriteColor: String = "yellow"
        set(value) {
            field = value
        }
        get() {
            return field
        }
}

//数据类
data class Cuboid(val length: Double, val width: Double, val height: Double)

//密封类，包含有限个类实现
sealed class MyShape

class MyTriangle : MyShape()
class MyRectangle : MyShape()