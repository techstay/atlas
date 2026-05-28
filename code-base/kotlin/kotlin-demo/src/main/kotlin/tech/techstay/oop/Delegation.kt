package tech.techstay.oop

import com.google.common.truth.Truth.assertThat
import java.time.LocalDateTime
import kotlin.properties.Delegates

fun main() {
    // lazy delegations
    val currentTime by lazy {
        LocalDateTime.now()
    }
    println(currentTime)
    Thread.sleep(1000)
    assertThat(currentTime).isEqualTo(currentTime)

    // observable delegations
    val observableDelegationDemo = ObservableDelegationDemo()
    observableDelegationDemo.value = "1"
    observableDelegationDemo.value = "100"

    // storing properties dynamically
    val user = UserMapDelegationDemo(mutableMapOf("id" to 1, "name" to "techstay", "age" to 18))
    println(user)
}

class ObservableDelegationDemo {
    var value: String by Delegates.observable("empty") { prop, old, new ->
        println("property ${prop.name} changed: $old -> $new")
    }
}

class UserMapDelegationDemo(val map: MutableMap<String, Any?>) {
    val id: Int by map
    var name: String by map
    var age: Int by map
    override fun toString(): String = "User(id:$id, name:$name, age:$age)"
}
