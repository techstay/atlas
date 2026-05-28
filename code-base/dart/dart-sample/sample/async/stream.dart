void main(List<String> args) async {
  print(
    await sumStream(
      Stream.fromIterable(
        Iterable.generate(10, (index) => index + 1),
      ),
    ),
  );
}

Future<int> sumStream(Stream<int> stream) async {
  var sum = 0;
  await for (final value in stream) {
    sum += value;
  }
  return sum;
}
