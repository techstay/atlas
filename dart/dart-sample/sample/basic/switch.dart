void main(List<String> args) {
  var score = 60;
  var rank = switch (score) {
    0 => 'worst',
    99 || 100 => 'perfect',
    // guard clause
    < 60 when score > 0 => 'failed',
    >= 60 => 'pass',
    _ => 'unexpected'
  };

  print(rank);

  switch (score) {
    case < 60:
      print('failed');
    case > 80:
      print('good');
    default:
      print('pass');
  }
}
