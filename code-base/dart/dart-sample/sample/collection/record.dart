void main(List<String> args) {
  // record
  var rec1 = (42, 'foo');
  print(rec1);

  (int, int) rec2 = (6, 4);
  print(rec2);

  // named record
  ({int a, int b}) rec3 = (b: 4, a: 6);
  print(rec3);

  var rec4 = (a: 6, b: 4);
  print(rec4);

  // record destructuring
  var (foo, bar) = rec1;
  print('foo: $foo, bar: $bar');

  // accessing record fields
  print(rec1.$2);
  print(rec3.b);

  print(baz());

  // Parameters destructuring is not supported yet
  // see also: https://github.com/dart-lang/language/issues/3001
  var result = List.generate(10, (index) => index + 1)
      .map((e) => (e, e * 2))
      .map((e) => e.$1 + e.$2)
      .toList();
  print(result);
}

// records often used in multiple returns
(int, int) baz() {
  return (42, 6);
}
