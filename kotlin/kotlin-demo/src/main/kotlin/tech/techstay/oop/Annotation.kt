package tech.techstay.oop

import kotlin.reflect.full.declaredFunctions

@Target(AnnotationTarget.CLASS, AnnotationTarget.FUNCTION)
@Repeatable()
annotation class MyAnnotation(val value: String = "default", val values: IntArray = [])

@MyAnnotation
@MyAnnotation("some value")
@MyAnnotation("some value", values = [1, 2, 3, 4, 5])
class MyAnnotationDemo {
    @MyAnnotation("annotation on f1")
    fun f1() {
    }

    @MyAnnotation("f2f2f2f2")
    fun f2() {
    }
}

fun main() {
    val annotations = MyAnnotationDemo::class.annotations
    annotations.filterIsInstance<MyAnnotation>()
        .forEach { annotation ->
            println("MyAnnotation on classes:")
            println("\tvalue: ${annotation.value}")
            println("\tvalues: ${annotation.values.joinToString(prefix = "[", postfix = "]")}")
        }

    MyAnnotationDemo::class.declaredFunctions.forEach { function ->
        function.annotations.filterIsInstance<MyAnnotation>()
            .forEach { annotation ->
                println("MyAnnotation on function ${function.name}:")
                println("\tvalue: ${annotation.value}")
                println("\tvalues: ${annotation.values.joinToString(prefix = "[", postfix = "]")}")
            }
    }
}
