package tech.techstay.serialization

import com.google.common.truth.Truth.assertThat
import kotlinx.serialization.Serializable
import kotlinx.serialization.decodeFromString
import kotlinx.serialization.encodeToString
import kotlinx.serialization.json.Json

@Serializable
data class MySerialObj(
    val id: Int,
    val name: String,
    val age: Int,
)

fun main() {
    val dataList = listOf(
        MySerialObj(1, "techstay", 18),
        MySerialObj(2, "zhang3", 16),
        MySerialObj(3, "li4", 22),
        MySerialObj(4, "wang5", 30)
    )

    val jsonList = Json.encodeToString(dataList)
    println(jsonList)

    val dataList2 = Json.decodeFromString<List<MySerialObj>>(jsonList)
    println(dataList2)
    assertThat(dataList2).isEqualTo(dataList)
}
