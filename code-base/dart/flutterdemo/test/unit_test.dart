import 'package:flutter_test/flutter_test.dart';

class Counter {
  int _count = 0;
  int get count => _count;
  void increment() {
    _count++;
  }
}

void main() {
  test('Counter increments smoke test', () {
    final counter = Counter();
    expect(counter.count, 0);

    counter.increment();
    expect(counter.count, 1);
  });
}
