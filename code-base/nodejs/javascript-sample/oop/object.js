let foo = 'abc'
let bar = { foo }
console.log(bar)

let x = { x: 100 }
let y = { y: 200 }
Object.assign(bar, x, y)
console.log(bar)

// properties
for (let [k, v] of Object.entries(bar)) {
  console.log(k, v)
}
