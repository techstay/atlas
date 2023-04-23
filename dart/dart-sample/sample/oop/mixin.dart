void main(List<String> args) {
  var my = MyColor();
  print(my.red());
  print(my.yellow());
}

mixin class Red {
  String red() => 'red';
}

mixin class Yellow {
  String yellow() => 'yellow';
}

class MyColor with Red, Yellow {}
