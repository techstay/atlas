void main(List<String> args) {
  var numberString = '0xcafe';
  print(int.parse(numberString));
  print(int.parse('10', radix: 16));

  var foo = 'abcde';
  print(foo.toLowerCase());
  print(foo.toUpperCase());
  print(foo.endsWith('de'));

  var bar = 'abc bbc ccb';
  print(bar.split(' '));
  print(bar.indexOf('bbc'));
  print(bar.indexOf('ccc'));
  print(bar.substring(4, 6));

  print(bar.isEmpty);
  print('   bb a'.trim());
}
