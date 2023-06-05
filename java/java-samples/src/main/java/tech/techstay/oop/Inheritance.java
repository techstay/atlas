package tech.techstay.oop;

import java.util.List;

// interfaces
interface HasLegs {
  void walk();
}


interface HasTail {
  void wagTail();
}


public class Inheritance {
  public static void main(String[] args) {
    Animal animal = new Animal("worm");
    Dog dog = new Dog("snoopy");

    animal.speak();
    dog.walk();
    dog.wagTail();

    // polymorphism
    List<Animal> animals = List.of(new Animal("null"), new Animal("not named"), new Dog("kitty"));
    animals.forEach(Animal::speak);
  }
}


// base classes
class Animal {
  protected String name;

  Animal(String name) {
    this.name = name;
  }

  public void speak() {
    System.out.format("animal %s may not speak%n", name);
  }
}


// derived classes
class Dog extends Animal implements HasLegs, HasTail {
  Dog(String name) {
    super(name);
  }

  public void walk() {
    System.out.format("dog %s walks%n", name);
  }

  public void wagTail() {
    System.out.format("dog %s wags a tail%n", name);
  }

  @Override
  public void speak() {
    System.out.format("dog %s wows%n", name);
  }
}

