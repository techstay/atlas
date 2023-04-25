package yitian.study.oop

fun main(args: Array<String>) {


}

//接口
interface Shape {
    val area: Double
}

class Triangle(val a: Double, val b: Double, val c: Double) : Shape {
    private val p = (a + b + c) / 2
    override val area: Double
        get() = Math.sqrt((p * (p - a) * (p - b) * (p - c)))

}

//或者使用惰性求值

class Triangle2(val a: Double, val b: Double, val c: Double) : Shape {
    private val p = (a + b + c) / 2
    override val area: Double by lazy {
        Math.sqrt((p * (p - a) * (p - b) * (p - c)))
    }

}