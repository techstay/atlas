package tech.techstay.oop

class Empty
data class Person(val name: String, val age: Int) {
    val nickname
        get() = this.name.substring(0..3)

    constructor() : this("default name", 0)
}

class DontCreateMe private constructor() {
}

fun main() {

    // can't be created
//    val dontCreateMe = DontCreateMe()
    val person = Person("techstay", 18)
    println(person.nickname)
}
