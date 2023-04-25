package yitian.study.function

fun main(args: Array<String>) {

    println("扩展方法:${"123".hello()}")
    println("扩展属性:${"cat".myProp}")
}

//扩展方法
fun String.hello() {
    println("$this say hello")
}

//扩展属性
val String.myProp: String
    get() {
        return this.toUpperCase() + this.toLowerCase()
    }