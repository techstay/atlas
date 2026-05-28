import 'dart:io';

void main(List<String> args) {
  var i = 0;
  while (i <= 10) {
    stdout.write('$i ');
    i++;
  }
  print('');

  // do while
  i = 0;
  do {
    stdout.write('$i ');
    i++;
  } while (i <= 10);
  print('');
}
