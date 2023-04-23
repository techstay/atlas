import 'dart:math';

void main(List<String> args) {
  print(Square(2).area);
  print(Circle(1).area);
}

// Abstracts classes and interfaces are slightly different from other languages
// In dart abstract classes can have abstract methods with no implementation
// while interfaces can have abstract methods with default implementations
interface class Shape {
  double get area => 0;
}

class Circle implements Shape {
  double radius;
  Circle(this.radius);

  @override
  double get area => pi * radius * radius;
}

class Square implements Shape {
  double side;
  Square(this.side);

  @override
  double get area => side * side;
}
