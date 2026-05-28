void main(List<String> args) {
  // explicit type declaration
  String text = 'text';
  print(text);

  // late variables
  late int age;

  // late variables must be initialized before using
  age = 10;
  print(age);

  // final and const
  final s = 'string';
  const pi = 3.14159;

  print(s);
  print(pi);
}
