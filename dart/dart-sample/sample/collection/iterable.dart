void main(List<String> args) {
  // empty
  var list = <int>[];
  print(list.isEmpty);
  print(list.isNotEmpty);

  // map
  list = [1, 2, 3, 4, 5];
  var doubledList = list.map((e) => e * 2);
  print(doubledList);

  // filter
  print(list.where((element) => element >= 3));

  // any all
  print(list.any((element) => element > 3));
  print(list.every((element) => element > 0));

  // fold reduce
  print(list.fold<int>(
      0, (previousValue, element) => previousValue + element * 2));
  print(list.reduce((value, element) => value + element * 2));
}
