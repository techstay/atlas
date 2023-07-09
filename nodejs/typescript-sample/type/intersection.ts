// intersection types
type A = { name: string }
type B = { age: number }

const intersection: A & B = { name: 'jack', age: 18 }
console.log(intersection)
