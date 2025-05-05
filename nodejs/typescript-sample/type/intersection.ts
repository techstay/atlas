// intersection types
interface A { name: string }
interface B { age: number }

const intersection: A & B = { name: 'jack', age: 18 }
console.log(intersection)
