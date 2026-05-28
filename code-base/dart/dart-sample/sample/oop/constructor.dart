// ignore_for_file: unused_local_variable
// ignore_for_file: prefer_initializing_formals

void main(List<String> args) {
  var foo = Foo(6, 4);
  var bar = Bar(6);
  var baz = Baz(4);
  var bas = Bas(10);

  var product = Product.fromFactory();
  print(product.productName);
}

class Foo {
  double a = 0;
  double b = 0;
  Foo(double a, double b) {
    this.a = a;
    this.b = b;
  }
}

class Bar {
  double a;
  // formal constructor parameters
  Bar(this.a);
  Bar.zero() : this(0);
}

class Baz {
  double a;
  Baz(this.a);
  // named constructors
  // initializer lists
  Baz.zero() : a = 0 {
    // constructor body
  }
  // redirecting constructors
  Baz.one() : this(1);
}

class Bas {
  final int x;
  // const constructors, constructing a compile-time object
  const Bas(this.x);
}

class Product {
  String productName;
  factory Product.fromFactory() => Product._internal('foo bar brand');
  Product._internal(this.productName);
}
