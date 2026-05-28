let foo = Symbol('foo')
let bar = Symbol('bar')
console.log(foo, bar)

let baz = {}
baz[foo] = 'foo'
baz[bar] = 'bar'
baz['x'] = 'x'
console.log(baz[foo], baz[bar])

console.log(Object.getOwnPropertySymbols(baz))
console.log(Reflect.ownKeys(baz))
