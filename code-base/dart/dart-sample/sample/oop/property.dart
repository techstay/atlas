void main(List<String> args) {
  var foo = Foo('HELLO');
  print(foo.name);
}

class Foo {
  String _name;
  Foo(this._name);

  // getters
  String get name => _name.toLowerCase();
  // setters
  set name(String name) => _name = name;
}
