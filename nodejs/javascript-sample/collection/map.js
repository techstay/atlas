// create new maps
let _emptyMap = new Map()
let map1 = new Map([['name', 'john3'], ['age', 18]])
console.log(map1)

// elements operations
map1.set('nickname', 'jj')
console.log(map1)

let age = map1.get('age')
console.log(age)

console.log(map1.has('name'))

map1.delete('nickname')
console.log(map1)

// iterate elements
for (let [k, v] of map1.entries()) {
  console.log(k, v)
}
map1.clear()
console.log(map1)
