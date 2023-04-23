void main(List<String> args) {
  pattern(42);
  pattern(true);
  pattern('bingo');
  pattern('foo bar');
  pattern(Object());
  pattern([1, 2, 3]);
  pattern(Point(6, 4));
}

void pattern(Object obj) {
  var result = switch (obj) {
    int i => 'integer: $i',
    true || false => 'boolean: $obj',
    'bingo' => 'bingo!',
    String s => 'string: $s',
    Point(x: var x, y: var y) => 'Point(x:$x, y:$y)',
    [var a, var b, var c] => 'list: [$a, $b, $c]',
    _ => '$obj'
  };

  print(result);
}

class Point {
  double x;
  double y;
  Point(this.x, this.y);
}
