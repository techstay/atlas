void main(List<String> args) {
  // nullable variables, default to null
  String? name;

  print(name);

  name = 'hello';
  print(name);

  print(name.toUpperCase());
  name = null;
  print(name?.toUpperCase());
}
