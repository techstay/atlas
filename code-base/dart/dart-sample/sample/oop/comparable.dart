void main(List<String> args) {
  var jack = Person('Jack', 24);
  var lucy = Person('Lucy', 18);

  print(jack.compareTo(lucy));

  var list = [jack, lucy];
  list.sort((a, b) => a.age.compareTo(b.age));
  print(list);
}

class Person implements Comparable<Person> {
  String name;
  int age;
  Person(this.name, this.age);

  @override
  int compareTo(Person other) => name.compareTo(other.name);

  @override
  String toString() => 'Person($name, $age)';

  @override
  int get hashCode => Object.hash(name, age);

  @override
  bool operator ==(Object other) =>
      other is Person && other.name == name && other.age == age;
}
