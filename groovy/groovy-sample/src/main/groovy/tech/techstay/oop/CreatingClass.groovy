package tech.techstay.oop

class Person {
  // no access modifiers indicate this is a property rather than a field
  String name;
  int age;
  // constructor
  Person(String name, int age) {
    this.name = name
    this.age = age
  }

  @Override
  String toString() {
    return "Person(name:${this.name}, age:${this.age})"
  }
}

def p = new Person("techstay", 18)
p.name = 'Jack'
p.age = 50
println(p)

