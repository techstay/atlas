void main(List<String> args) {
  // dates
  var now = DateTime.now();
  print(now);
  var year2000 = DateTime(2000, 1, 1);
  print(year2000);
  var year2000InUtc = DateTime.utc(2000, 1, 1);
  print(year2000InUtc);

  // adjusting
  print(year2000.add(const Duration(days: 366)));
  print(year2000.subtract(const Duration(days: 7)));

  var duration = now.difference(year2000);
  print(duration.inDays ~/ 365);
}
