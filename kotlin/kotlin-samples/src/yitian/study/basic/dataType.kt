package yitian.study.basic

fun numbers() {
    val byte: Byte = 5
    val short: Short = 16
    val integer: Int = 5
    val long: Long = 30

    val float: Float = 2.4F
    val double: Double = 3.1415

    //需要显式转换
    val anotherInteger: Int = short.toInt()
}

fun bitOperators() {
    //左移
    var l = 0b1011 shl 2
    //右移
    var r = 0b1011 shr 2
    //无符号右移
    var ur = 0b1011 ushr 2
    //与
    val a = 1 and 2
    //或
    val b = 1 or 2
    //非
    val n = 1.inv()
    //异或
    val d = 2 xor 3
}

fun character() {
    val c: Char = 'c'
    val line = '\n'
    val d = '\u0000'
}

fun booleans() {
    val t = true
    val f = false
    //与或非
    val allRight = t && f
    val noRight = !t
    val trueOrFalse = t || f
}

fun arrays() {
    val array1 = arrayOf(1, 2, 3, 4, 5)
    println("数组1:${array1.joinToString()}")
    val array2 = kotlin.arrayOfNulls<Int?>(5)
    println("数组2:${array2.joinToString()}")
    //工厂方法创建数组
    val squareArray = Array(5, { it * it })
    println("工厂方法创建数组:${squareArray.joinToString()}")
}

fun strings() {
    val string: String = "普通字符串\t可以包含转义字符"
    val rawString: String = """原始字符串，转义字符\t会直接显示"""
    println(string)
    println(rawString)

    val i = 5
    println("内插字符串，可以包含任意变量:$i")
    println("也可以包含任意表达式:${i * i}")
}

fun main(args: Array<String>) {
    numbers()
    bitOperators()
    character()
    booleans()
    arrays()
    strings()
}