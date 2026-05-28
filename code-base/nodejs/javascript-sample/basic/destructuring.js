// destructuring arrays
let array = [1, 2, 3, 4]
let [a, b, c] = array
let [x, y] = array
let [, , , , z] = array
let [head, , ...tail] = array

console.log(a, b, c, x, y, z, head, tail)

// default variables destructuring
let [d = 'abc'] = [undefined]

// object destructuring
let { x: g, y: h, z: i } = { x: 1, y: 2, z: 3 }

console.log(d, g, h, i)
