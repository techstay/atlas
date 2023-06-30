(int a, int b) foo()
{
  return (4, 2);
}

var (a, b) = foo();
System.Console.WriteLine($"a={a}, b={b}");

var tuple = foo();
var x = tuple.Item1;
var y = tuple.Item2;
var j = tuple.a;
var k = tuple.b;

System.Console.WriteLine($"a={x}, b={y}");
System.Console.WriteLine($"a={j}, b={k}");
