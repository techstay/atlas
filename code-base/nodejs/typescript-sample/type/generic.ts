function first<T> (arr: T[]): T {
  return arr[0]
}

console.log(first([1, 2, 3]))
console.log(first(['a', 'b', 'c']))
console.log(first([true, false]))
console.log(first<string>(['a', 'b', 'c']))
