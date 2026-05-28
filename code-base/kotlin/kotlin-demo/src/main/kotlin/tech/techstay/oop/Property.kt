package tech.techstay.oop

class PropertyDemo {
    val prop1: String = "abc"

    // custom property
    var prop2: String = ""
        get() {
            return field + field
        }
        set(value) {
            // backing fields
            field = value.uppercase()
        }
}

fun main() {
    val propertyDemo = PropertyDemo()
    propertyDemo.prop2 = "xyz"
    println(propertyDemo.prop2)
}
