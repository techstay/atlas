void main(List<String> args) {
  print('Jack'.hello());
  print(6.times2());
  print(6.times(4));

  // explicit calling
  print(MathOperation(6).times(4));
}

extension MyOperation on String {
  String hello() => 'hello, $this!';
}

extension MathOperation on int {
  int times2() => this * 2;
  int times(int i) => this * i;
}
