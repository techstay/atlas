// creating a class
class Person {
  name = ''
  // private properties
  static #count = 0

  static {
    // in static blocks we can initialize properties
  }
  // constructors
  constructor(name = 'uninitialized') {
    this.name = name
    Person.#count++
  }

  // setters and getters
  get username () {
    return this.name
  }

  set username (value) {
    console.log(`changing property: ${this.username} -> ${value}`)
    this.name = value
  }
  static peopleCount () { return Person.#count }

  toString () {
    return `Person:(name: ${this.name})`
  }
}

let p = new Person('John3')
console.log(p)

let p2 = new Person()
console.log(p2)

p2.username = '666'

console.log(Person.peopleCount())
