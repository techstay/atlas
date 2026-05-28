package tech.techstay.oop

trait Fly {
  void fly() { println('I can fly') }
}

trait Run {
  void run() { println('I can run') }
}

trait Walk {
  void walk() { println('I can walk') }
}

class Creature implements Fly, Run, Walk {

}

def creature = new Creature()
creature.walk()
creature.run()
creature.fly()

