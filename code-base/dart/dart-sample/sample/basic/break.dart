import 'dart:io';

void main(List<String> args) {
  for (int i = 0; i <= 5; i++) {
    if (i == 3) break;
    stdout.write('$i ');
  }
  print('');

  for (int i = 0; i <= 5; i++) {
    if (i == 3) continue;
    stdout.write('$i ');
  }
  print('');
}
