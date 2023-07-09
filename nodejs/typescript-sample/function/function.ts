function greet (name: string) {
  console.log(`Hello, ${name}!`)
}

greet('John')

function double (num: number): number {
  return num * 2
}

console.log(double(4))


function printNumbers (...numbers: number[]) {
  for (const i of numbers) {
    console.log(i)
  }
}
printNumbers(1)
printNumbers(1, 2, 3, 4, 5)
