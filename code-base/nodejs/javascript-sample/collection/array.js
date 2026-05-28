const arr1 = [1, 2, 3, 4, 5]
const arr2 = [...'abcde']
const arr3 = Array.of(1)
console.log(arr1, arr2, arr3)

// searching
console.log(arr1.find((e) => e > 3))
console.log(arr1.findIndex((e) => e > 3))
console.log(arr1.findLast((e) => e > 3))

// including
console.log(arr1.includes(40))

// flat
console.log([1, 2, [3, 4]].flat())

// index
console.log(arr1.at(2))
console.log(arr1.at(-2))
