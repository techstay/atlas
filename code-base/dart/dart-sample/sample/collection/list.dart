void main(List<String> args) {
  // lists
  var li1 = [1, 2, 3, 4, 5];
  var li2 = [
    1,
    2,
  ];
  var emptyList = <String>[];
  assert(emptyList.isEmpty);

  var ones = List.filled(5, 1);
  assert(ones.length == 5);
  assert(ones.every((element) => element == 1));

  // elements operations
  li2.add(3);
  li2.addAll([4, 5, 6]);
  assert(li2.length == 6);
  li2.remove(3);
  li2.removeAt(4);
  print(li2);
  li2.clear();
  assert(li2.isEmpty);

  // list comprehension
  var li3 = [1, 2, if (li2.length == 2) 3];
  var li4 = [for (var i in li1) i * 2];
  print(li3);
  print(li4);

  // list sorting
  var foo = [6, 5, 2, 3, 1];
  foo.sort((a, b) => a.compareTo(b));
  print(foo);
}
