let str = '\u{41}\u{42}\u{43}'
console.log(str)

let hanzi = '\u{6C49}\u{5B57}'
console.log(hanzi)
console.log('\u6C49\u5B57')

// iterating strings
for (let s of 'foo') {
  console.log(s)
}

for (let s of '汉字') {
  console.log(s)
}

// string interpolation
let username = 'john3'
let greeting = `hello, ${username}`
console.log(greeting)

// code point
console.log(String.fromCodePoint(0x5B57))
console.log('汉'.codePointAt(0))

// string methods
console.log('abc'.repeat(3))
console.log('abc'.startsWith('a'))
console.log('abc'.endsWith('c'))
console.log('abc'.padStart(8, '-'))
console.log('abc'.padEnd(8, '-'))
console.log('abc'.replaceAll('a', 'c'))
