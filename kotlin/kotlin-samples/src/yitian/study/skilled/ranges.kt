package yitian.study.skilled

fun main(args: Array<String>) {
    intRange()
    intRangeDown()
    intRangeByStep()
    intRangeWithoutLast()
    customRange()
}

fun intRange() {
    for (i in 1..5) {
        print("$i ")
    }
    println()
}

fun intRangeDown() {
    for (i in 4 downTo 1) {
        print("$i ")
    }
    println()
}

fun intRangeByStep() {
    for (i in 1..10 step 2) {
        print("$i ")
    }
    println()
}

fun intRangeWithoutLast() {
    for (i in 1 until 10) {
        print("$i ")
    }
    println()
}

fun customRange() {
    val start = MyValue(1)
    val end = MyValue(10)

    //用作迭代
    for (i in start..end) {
        print("$i ")
    }
    println()
    //用作范围判断
    val v = MyValue(5)
    val result = v in start..end
    println("范围判断结果是:$result")
}

/*要实现自定义范围，类需要重载rangeTo运算符，返回一个ClosedRange对象
还需要实现Comparable接口以进行比较
这里还重载了+运算符，方便进行加法运算*/
class MyValue(val v: Int) : Comparable<MyValue> {
    override fun compareTo(other: MyValue): Int {
        return v - other.v
    }

    operator fun plus(other: Int) = MyValue(v + other)

    operator fun rangeTo(other: MyValue) = MyValueRange(this, other)
    override fun toString(): String {
        return "$v"
    }
}

/*实现ClosedRange和Iterable接口，即可进行范围运算和迭代
*/
class MyValueRange(override val start: MyValue, override val endInclusive: MyValue) : ClosedRange<MyValue>, Iterable<MyValue> {
    override fun iterator(): Iterator<MyValue> {
        return MyValueIterator(this)
    }

    //不要使用IDEA的自动改正把范围判断改为[a..b]形式，否则会无限递归
    override fun contains(value: MyValue): Boolean {
        return value >= start && value <= endInclusive
    }
}

/*实现Interable接口的hasNext和next方法，即可进行迭代 */
class MyValueIterator(val range: MyValueRange) : Iterator<MyValue> {
    private var current: MyValue = range.start
    override fun hasNext(): Boolean {
        return current <= range.endInclusive
    }

    override fun next(): MyValue {
        val v = current
        current += 1
        return v
    }
}