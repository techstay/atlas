package yitian.study.basic

fun ifStmt() {
    val a = 3
    val b = 4
    //普通if语句
    if (a < b) {

    }
    //带else的if语句
    if (a <= b) {

    } else {

    }
    /*if表达式，必须带有else语句
    代码段中最后一个表达式作为if表达式的值
    */
    val bigger = if (a < b) {
        b
    } else {
        a
    }
}

fun whenStmt() {
    val i = 3
    when (i) {
        1 -> println("i是1")
        2 -> println("i是2")
        3, 4 -> println("i是3或4")
        (25 / 5) -> println("判断条件也可以是其它表达式")
        !in 10..20 -> println("i不在10到20之间")
        else -> {
            println("i不是上面几个数字")
        }
    }
    //when语句也可以作为表达式使用
    val someTexts = "1234 567"
    val hasSpace = when (someTexts) {
        is String -> someTexts.contains(" ")
        else -> false
    }
    println("结果是否包含空格:$hasSpace")
    //when语句还可以作为if语句使用，这时候不需要给定变量
    val m = 3
    when {
        m == 1 -> println("m是1")
        m - 2 == 0 -> println("m是2")
        else -> println("m既不是1也不是2")
    }

}

fun forStmt() {
    val array = intArrayOf(1, 2, 3, 4, 5)
    //普通遍历
    for (i in array) {
        print("$i ")
    }
    println()
    //使用数组下标遍历
    for (i in array.indices) {
        print("${array[i]} ")
    }
    println()
    //同时遍历下标和值
    for ((index, value) in array.withIndex()) {
        print("[index:$index,value:$value] ")
    }
    println()

}

fun whileStmt() {
    //和其他语言的while、dowhile类似
    var i: Int = 5
    while (i >= 0) {
        i--
    }

    i = 5
    do {
        i--
    } while (i > 0)
}

fun jumpAndReturnStmt() {
    //break语句
    for (i in 10..20) {
        if (i % 2 == 0)
            break
        print("$i ")
    }
    println()
    //continue语句
    for (i in 10..20) {
        if (i % 2 == 0)
            continue
        print("$i ")
    }
    println()
    //使用标签多重跳出
    outer@ for (i in 1..9) {
        inner@ for (j in 1..i) {
            if (i == j) {
                break@inner
            }
        }
    }
    //return语句，如果只想跳出匿名函数需要添加标签
    (10..20).forEach inner@ {
        if (it % 7 == 0) {
            return@inner
        }
    }
    println("没有直接返回整个函数")
}

fun main(args: Array<String>) {
    ifStmt()
    whenStmt()
    forStmt()
    jumpAndReturnStmt()
}