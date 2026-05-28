import 'package:test/test.dart';

void main() {
  test('arithmetic operators', () {
    expect(6 / 4, 1.5);
    expect(6 ~/ 4, 1);
  });

  test('rational operators', () {
    expect(4 > 2, true);
    expect(3 >= 3, true);
    expect(6 < 4, false);
  });

  test('type cast operators', () {
    // ignore: unnecessary_type_check
    expect('abc' is Object, true);
    expect('abc' is! int, true);
  });

  test('cascade notation', () {
    var sb = StringBuffer()
      ..write('foo')
      ..write('bar');
    expect(sb.toString(), 'foobar');
  });
}
