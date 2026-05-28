import 'dart:math';

void main(List<String> args) {
  var random = Random();
  var list = List.generate(10, (index) => random.nextInt(10));
  print(list);

  // dice game
  var dice = Map<int, int>.fromIterable(
    Iterable.generate(6, (index) => index + 1),
    value: (_) => 0,
  );

  const n = 1000000;
  for (var e in Iterable.generate(n, (_) => random.nextInt(6) + 1)) {
    dice[e] = dice[e]! + 1;
  }

  print(dice);
}
