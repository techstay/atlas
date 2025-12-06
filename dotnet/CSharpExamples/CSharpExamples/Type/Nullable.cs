namespace CSharpExamples.Type;

class NullableShowCase
{
  [Test]
  public void Nullable()
  {
    double? number = 3.14;
    Console.WriteLine(number);

    // allow value types to be nullable
    number = null;
    Console.WriteLine(number ?? -1);
    Console.WriteLine(number.GetValueOrDefault(-1));

    number = number ?? 3.14159;
    Console.WriteLine(number);

    // check a type is nullable or not
    Console.WriteLine($"HasValue: {number.HasValue}");
  }
}

