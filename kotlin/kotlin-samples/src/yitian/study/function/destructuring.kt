package yitian.study.function

fun main(args: Array<String>) {
    destructObject()
    returnFromFunc()
    destructMap()
}

//解构对象需要类重载componentN运算符
class MyPerson(val name: String, val age: Int) {
    operator fun component1(): String = name
    operator fun component2(): Int = age
}

//data类会自动实现componentN运算符
data class MyPerson2(val name: String, val age: Int)

fun destructObject() {
    val myP1 = MyPerson("yitian", 24)
    val (name, age) = myP1
    println("名字是:$name 年龄是:$age")

    val myP2 = MyPerson2("yitian", 24)
    val (name2, age2) = myP1
    println("名字是:$name2 年龄是:$age2")

}

//返回多个值
fun returnTwoObj(): Pair<String, String> {
    return Pair("yitian", "hello")
}

fun returnFromFunc() {
    val (s1, s2) = returnTwoObj()
    println("s1:$s1 s2:$s2")
}

//解构Map
fun destructMap() {
    val map = mapOf(1 to 1,
            2 to 2,
            3 to 3,
            4 to 4)
    for ((k, v) in map) {
        print("$k:$v ")
    }
    println()
}