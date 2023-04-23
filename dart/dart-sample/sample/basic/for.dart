import 'dart:io';

void main(List<String> args) {
  // for in
  var array = [1, 2, 3, 4, 5];
  for (final e in array) {
    stdout.write('$e ');
  }
  print('');

  // for loop
  for (int i = 0; i <= 5; i++) {
    stdout.write('$i ');
  }
  print('');
}
