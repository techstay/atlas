void main(List<String> args) {
  var dog = Dog('snoopy');
  dog.speak();
}

abstract class Animal {
  // abstract methods
  void speak();
}

class Dog extends Animal {
  String name;
  Dog(this.name);

  @override
  void speak() {
    print('Dog $name sparks');
  }
}
