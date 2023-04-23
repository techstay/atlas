void main(List<String> args) {
  print(isEven(6));
  print(isOdd(4));

  setFlags(f1: true, f2: false);
  setFlags(f1: false);
  setFlags();
  foo(true, false);
  foo(true, false, false);

  // lambda functions
  f(int n) => n * 2;
  print(f(2));
}

// type annotations can be omitted
// bool isEven(n)
bool isEven(int n) {
  return n % 2 == 0;
}

// single line functions
bool isOdd(int n) => n % 2 != 0;

// named parameters
void setFlags({bool? f1, bool? f2 = false}) {
  print('f1:$f1, f2: $f2');
}

// optional positional parameters
void foo(bool f1, bool f2, [bool f3 = true]) {
  print('f1: $f1, f2: $f2, f3: $f3');
}
