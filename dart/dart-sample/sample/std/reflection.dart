import 'dart:mirrors';

void main(List<String> args) {
  var foo = ExampleClazz('Jack', 18);
  var instanceMirror = reflect(foo);
  var classMirror = instanceMirror.type;

  // getting fields
  var nameMirror = instanceMirror.getField(Symbol('name'));
  var ageMirror = instanceMirror.getField(Symbol('age'));
  print(nameMirror.reflectee);
  print(ageMirror.reflectee);

  // calling methods
  var helloMirror = classMirror.instanceMembers[Symbol('hello')];
  print(helloMirror!.qualifiedName);
  instanceMirror.invoke(Symbol('hello'), []);
  print(classMirror.invoke(Symbol('className'), []));

  // instantiating
  var barMirror = classMirror.newInstance(Symbol.empty, ['Tom', 20]);
  // now we can calling methods from the object
  ExampleClazz bar = barMirror.reflectee;
  bar.hello();
}

class ExampleClazz {
  String name;
  int age;
  ExampleClazz(this.name, this.age);
  void hello() => print('Hello $name');
  static String className() => 'Foo';
}
