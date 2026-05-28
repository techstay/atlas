void main(List<String> args) {
  var fun = MyFunction();
  print(fun('abc'));
}

class MyFunction {
  String call(String str) => str.toUpperCase();
}
