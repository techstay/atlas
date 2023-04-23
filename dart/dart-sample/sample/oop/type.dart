void main(List<String> args) {
  var str = 'abc';
  print(str.runtimeType);

  var i = 42;
  print(i.runtimeType);

  var exception = Exception('an exception');
  print(exception.runtimeType);
}
