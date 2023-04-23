void main(List<String> args) {
  // using `dart --enable-asserts <filename>` to enable asserts
  assert(plus(6, 4) == 10, '6 + 4 should be 10');
  assert(plus(6, 4) == 20, '6 + 4 should be 10');
}

int plus(int a, int b) => a + b;
