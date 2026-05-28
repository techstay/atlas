/* -------------------------------------------------------------------------- */
/*                               Immutable Maps                               */
/* -------------------------------------------------------------------------- */

// Creating Maps
Map("a" -> 1, "b" -> 2, "c" -> 3)
Map.empty[String, Int]
Map("a" -> 1, "b" -> 2).withDefaultValue(0)

// Accessing elements
val map = Map("a" -> 1, "b" -> 2, "c" -> 3)
map("a") // 1
map.get("b") // Some(2)
map.get("d") // None

val map2 = Map("a" -> 1, "b" -> 2, "c" -> 3).withDefaultValue(0)
map2("d")
map2.get("d")

for (k, v) <- map do println(s"Key: $k, Value: $v")
