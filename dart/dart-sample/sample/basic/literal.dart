// ignore_for_file: unused_local_variable

void main(List<String> args) {
  // numbers
  var int = 42;
  var float = 3.14;
  print(int);
  print(float);

  var hex = 0XDEADBEEF;
  var exponent = 3.14e6;

  // boolean
  var truth = true && false;
  print(truth);

  // null
  var none;
  print(none);

  // strings
  var name = 'abcd';
  print(name);

  // collections
  var array = [1, 2, 3, 4, 5];
  var record = (42, 'foo', 'bar', 3.1415);
  var dictionary = {'name': 'jack', 'age': 18};
  print(array);
  print(record);
  print(dictionary);
}
