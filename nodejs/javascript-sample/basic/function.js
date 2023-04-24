function foo (a = 100) {
  return 42
}

console.log(foo())

// recursive functions
function fibonacci (n) {
  if (n == 0 || n == 1) {
    return 1
  } else {
    return n * fibonacci(n - 1)
  }
}
console.log(fibonacci(5))

// tail recursive functions
function factorial (n, acc = 1) {
  if (n == 0 || n == 1) {
    return acc
  } else {
    return factorial(n - 1, acc * n)
  }
}
console.log(factorial(5))
// no stack overflow
console.log(factorial(50))

// rest arguments
function sum (...numbers) {
  let sum = 0
  for (let n of numbers) {
    sum += n
  }
  return sum
}
console.log(sum(1, 2, 3, 4, 5))

