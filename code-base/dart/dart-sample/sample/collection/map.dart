void main(List<String> args) {
  // maps
  var m1 = <String, String>{};
  var m2 = {'foo': 'foofoo', 'bar': 'bar'};

  // adding elements
  m1['foo'] = 'bar';
  print(m1);
  m2['bar'] = 'baz';
  print(m2);

  // removing elements
  m1.remove('foo');
  print(m1);

  // retrieving keys and values
  print(m2.keys);
  print(m2.values);

  // containing
  print(m2.containsKey('foo'));
  print(m2.containsValue('baz'));
}
