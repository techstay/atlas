package tech.techstay.basic

// creating new maps
def emptyMap = [:]
def initializedMap = [a: 1, b: 2]

// adding elements
emptyMap.name = 'techstay'
emptyMap.age = 18
assert emptyMap.name == 'techstay'
assert emptyMap['age'] == 18

// iterating maps
initializedMap.each { entry -> "key: $entry.key, value: $entry.value" }
initializedMap.eachWithIndex { entry, int i -> "$entry.key $entry.value $i" }
initializedMap.eachWithIndex { k, v, i -> "$k $v $i" }

// removing items
println("before removing: $emptyMap")
emptyMap.remove('age')
println("after removing: $emptyMap")

initializedMap.removeAll { it.value % 2 == 0 }
println("after removing: $initializedMap")
