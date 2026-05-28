void main() {
  var score = 80;

  if (score < 60) {
    print('failed');
  } else if (score == 100) {
    print('perfect');
  } else {
    print('good');
  }

  // conditional operator/ternary operator
  var result = score >= 60 ? 'pass' : 'failed';
  print(result);

  // if case
  if (score case >= 60) {
    print('good');
  } else {
    print('bad');
  }
}
