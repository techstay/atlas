abstract class Animal {
  protected name: string
  constructor(name: string) {
    this.name = name
  }

  move (): void {
    console.log(`${this.name} moves`)
  }
  abstract speak (): void
}

class Cat extends Animal {
  move (): void {
    console.log(`${this.name} moves with four legs`)
  }
  speak (): void {
    console.log(`${this.name} meows`)
  }
}

const cat = new Cat('kitty')
cat.move()
cat.speak()
