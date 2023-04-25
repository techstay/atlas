package yitian.study.oop


open class Person /*主构造方法*/ constructor(name: String) {
    val name: String = name

    constructor() : this("") {
        //其他构造方法
    }

    init {
        //初始化代码在这里
    }

    open fun say(something: String) {
        println("$name say $something")
    }
}

//父类必须用open标记
//可重写的方法也必须使用open标记
class Teacher(name: String) : Person(name) {
    override fun say(something: String) {
        super.say(something + "1")
    }
}

