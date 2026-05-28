void main(List<String> args) {
  print(generateIntegers(5));
  print(generateIntegers(10));

  print(generateIntegersRecursively(5));
}

// synchronous generators
Iterable<int> generateIntegers(int n) sync* {
  int k = 0;
  while (k <= n) {
    yield k++;
  }
}

// asynchronous generators
Stream<int> generateAsyncIntegers(int n) async* {
  int k = 0;
  while (k <= n) {
    yield k++;
  }
}

// recursive generators
Iterable<int> generateIntegersRecursively(int n) sync* {
  if (n > 0) {
    yield n;
    yield* generateIntegersRecursively(n - 1);
  }
}
