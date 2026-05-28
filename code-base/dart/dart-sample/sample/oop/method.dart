void main(List<String> args) {
  var a = MyValue(6);
  var b = MyValue(4);
  print(a.add(b));
  print(a + b);
  print(a == b);
  print(a != b);

  var rect = Rectangle(6, 4);
  rect.width2 = 5;
  print(rect.area);
}

class MyValue {
  double v;
  MyValue(this.v);

  // methods
  MyValue add(MyValue w) => MyValue(v + w.v);

  // operator overloading
  @override
  bool operator ==(Object other) => other is MyValue && v == other.v;
  // implementing equals requiring implementing hashCode
  @override
  int get hashCode => v.hashCode;
  MyValue operator +(MyValue other) => add(other);
  @override
  String toString() => 'MyValue($v)';
}

class Rectangle {
  double height;
  double width;
  Rectangle(this.height, this.width);

  // getters and setters
  set width2(double value) => width = value * 2;
  double get area => height * width;
}
