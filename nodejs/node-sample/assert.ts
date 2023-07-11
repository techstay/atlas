import assert from 'node:assert/strict'

function add (a: number, b: number) {
  return a + b
}

assert(add(6, 4) == 10, 'not equal')
assert(add(6, 4) == 9)
