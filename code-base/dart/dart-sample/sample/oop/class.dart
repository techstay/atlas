// ignore_for_file: unused_local_variable

void main(List<String> args) {
  for (int i = 0; i < 5; i++) {
    Person('no. $i');
  }
  print(Person.getPeopleCount());
}

class Person {
  String name;
  // class variables
  static int peopleCount = 0;
  Person(this.name) {
    peopleCount++;
  }
  static getPeopleCount() => peopleCount;
}
