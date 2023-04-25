package yitian.study.oop

fun main(args: Array<String>) {

    var light = TraphicLight.red
    for (i in 1..3) {
        light = light.turn()
        print("$light ")
    }
    println()

    //枚举转字符串
    val str: String = light.toString()
    println("枚举值是$str")

    //字符串转枚举
    val e: TraphicLight = TraphicLight.valueOf(str)
    println("枚举值是$e")
}

//枚举类
enum class Color {
    red, blue, yellow
}

//每个枚举值都是枚举类的对象
enum class TraphicLight {
    green {
        override fun turn(): TraphicLight = yellow
    },
    yellow {
        override fun turn(): TraphicLight = red
    },
    red {
        override fun turn(): TraphicLight = green
    };

    abstract fun turn(): TraphicLight
}