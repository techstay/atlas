import 'dart:math';

void main(List<String> args) {
  const N = 10000000;
  var dice = {for (var i = 1; i <= 6; i++) i: 0};

  for (var i = 0; i < N; i++) {
    var n = Random().nextInt(6) + 1;
    dice[n] = dice[n]! + 1;
  }

  print(dice);
}
