void main(List<String> args) {
  try {
    foo(1);
  } on String catch (s) {
    print(s);
    rethrow;
  } on Bar {
    print('throwing bar');
  } on Exception catch (e) {
    print('caught exception: $e');
  } finally {
    print('always executed, doing some cleaning works');
  }
}

// dart can throw any objects not just exceptions and errors
void foo(int n) {
  switch (n) {
    case 1:
      throw 'one';
    case 2:
      throw Exception('2');
    case 3:
      throw Bar();
  }
}

class Bar {}
