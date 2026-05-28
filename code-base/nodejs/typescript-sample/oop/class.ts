class Person {
  // private fields
  #name: string
  #age: number

  static #peopleCount = 0

  // constructors
  constructor(name: string, age: number) {
    this.#age = age
    this.#name = name
    Person.#peopleCount++
  }

  // getters and setters
  get name (): string {
    return this.#name
  }
  set name (value: string) {
    this.#name = value
  }

  get age (): number {
    return this.#age
  }
  set age (value: number) {
    this.#age = value
  }

  // methods
  sleep (): void {
    console.log(`have a good night, ${this.#name}`)
  }
  static getPeopleCount (): number {
    return Person.#peopleCount
  }
}

const p = new Person('zs', 18)
p.name = 'john'

p.sleep()
new Person('jj', 6)
console.log(Person.getPeopleCount())
