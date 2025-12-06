namespace CSharpExamples.Basic;

class OperatorShowCase
{
  [Test]
  public void ArithmeticOperators()
  {
    var a = 10;
    var b = 3;

    Console.WriteLine($"Addition: {a} + {b} = {a + b}");
    Console.WriteLine($"Subtraction: {a} - {b} = {a - b}");
    Console.WriteLine($"Multiplication: {a} * {b} = {a * b}");
    Console.WriteLine($"Division: {a} / {b} = {a / b}");
    Console.WriteLine($"Modulus: {a} % {b} = {a % b}");
  }

  [Test]
  public void ComparisonOperators()
  {
    var x = 5;
    var y = 10;

    Console.WriteLine($"{x} == {y}: {x == y}");
    Console.WriteLine($"{x} != {y}: {x != y}");
    Console.WriteLine($"{x} > {y}: {x > y}");
    Console.WriteLine($"{x} < {y}: {x < y}");
    Console.WriteLine($"{x} >= {y}: {x >= y}");
    Console.WriteLine($"{x} <= {y}: {x <= y}");
  }

  [Test]
  public void LogicalOperators()
  {
    var p = true;
    var q = false;

    Console.WriteLine($"p && q: {p && q}");
    Console.WriteLine($"p || q: {p || q}");
    Console.WriteLine($"!p: {!p}");
  }

  [Test]
  public void AssignmentOperators()
  {
    var num = 10;
    Console.WriteLine($"Initial value: {num}");

    num += 5;
    Console.WriteLine($"After += 5: {num}");

    num -= 3;
    Console.WriteLine($"After -= 3: {num}");

    num *= 2;
    Console.WriteLine($"After *= 2: {num}");

    num /= 4;
    Console.WriteLine($"After /= 4: {num}");

    num %= 3;
    Console.WriteLine($"After %= 3: {num}");
  }

  [Test]
  public void UnaryOperators()
  {
    var value = 5;
    Console.WriteLine($"Original value: {value}");

    Console.WriteLine($"Unary plus: +{value} = {+value}");
    Console.WriteLine($"Unary minus: -{value} = {-value}");

    Console.WriteLine($"Increment: {value}++ = {value++}");
    Console.WriteLine($"After increment: {value}");

    Console.WriteLine($"Decrement: {value}-- = {value--}");
    Console.WriteLine($"After decrement: {value}");
  }

  [Test]
  public void TernaryOperator()
  {
    var age = 20;
    var eligibility = age >= 18 ? "Eligible to vote" : "Not eligible to vote";
    Console.WriteLine($"Age: {age}, Eligibility: {eligibility}");
  }

  [Test]
  public void NullCoalescingOperator()
  {
    string? name = null;
    var displayName = name ?? "Guest";
    Console.WriteLine($"Hello, {displayName}!");
  }
}
