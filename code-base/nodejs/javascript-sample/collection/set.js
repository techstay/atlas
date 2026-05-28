// create new sets
let set1 = new Set([1, 2, 2, 3, 3, 3])
console.log(set1)
console.log(set1.size)

// remove duplicated elements
let list1 = [1, 1, 2, 3, 3, 4, 4, 4]
let list2 = [...new Set(list1)]
console.log(list2)

// set operations
set1.add(5)
console.log(set1)
console.log(set1.has(5))
set1.delete(5)
console.log(set1)

// iterate sets
for (let e of set1.values()) {
  console.log(e)
}

// clear
set1.clear()
console.log(set1)
