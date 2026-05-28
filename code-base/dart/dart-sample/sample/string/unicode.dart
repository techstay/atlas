import 'package:characters/characters.dart';

void main(List<String> args) {
  // unicode
  var unicode = '😆';
  print(unicode);

  print(unicode.characters.length);
  print(unicode.codeUnitAt(0).toRadixString(16));

  // unicode code point
  print('\u{1f606}');
}
