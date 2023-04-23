void main(List<String> args) {
  // sets
  var s1 = {1, 2, 3};
  var s2 = {1, 2, 5};
  var s3 = <int>{};

  // set operations
  print(s1.intersection(s2));
  print(s1.union(s2));
  print(s1.difference(s2));

  // adding elements
  s3.add(3);
  s3.addAll([1, 2, 3, 4]);
  print(s3);

  // removing elements
  s3.remove(3);
  print(s3);

  // containing
  print(s3.contains(1));
  print(s3.containsAll([1, 2, 3, 4]));
}
