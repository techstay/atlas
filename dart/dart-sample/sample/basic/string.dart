void main(List<String> args) {
  // strings
  var name = 'jack';
  print(name);

  var multilineText = '''
foo
bar''';
  print(multilineText);

  var rawString = r'C:\Windows\system32\drivers\etc\hosts';
  print(rawString);

  // string interpolation
  print('hello, $name');
}
