package tech.techstay.oop

open class SuperClass {
    var prop1: String

    init {
        prop1 = "prop1"
        println("in superclass prop1 initialization block")
    }

    var prop2: String = "prop2".also { println("in superclass prop2 initialization block") }

    constructor(prop1: String, prop2: String) {
        this.prop1 = prop1
        this.prop2 = prop2
        println("in superclass secondary constructor block")
    }

    open fun f1() {
        println("in superclass f1")
    }
}

class SubClass(prop1: String = "default", prop2: String = "xyz") : SuperClass(prop1, prop2) {
    init {
        println("in subclass initialization block")
    }

    override fun f1() {
        super.f1()
        println("in subclass f1")
    }
}

fun main() {
    val obj = SubClass()
    obj.f1()
}
