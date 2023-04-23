void main(List<String> args) {
  var text = 'Long long ago, there is a princess living in the castle.';
  var regex = RegExp(r'\b\w{6}\b');

  print(text.contains(regex));
  print(text.replaceAll(regex, 'XXX'));

  print(regex.hasMatch(text));
  regex.allMatches(text).forEach((e) => print(e.group(0)));
}
