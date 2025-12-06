namespace CSharpExamples.Function;

class FunctionShowCase
{
  [Test]
  public void SimpleFunction()
  {
    Console.WriteLine("This is a simple function.");
  }

  [Test]
  [Arguments("Alice", 32)]
  public void MultipleParametersFunction(string name, int age)
  {
    Console.WriteLine($"Name: {name}, Age: {age}");
  }


  [Test]
  [Arguments("John Doe", 32)]
  [Arguments("Alice")]
  [Arguments()]
  public void DefaultParameterFunction(string name = "John Doe", int age = 32)
  {
    Console.WriteLine($"Name: {name}, Age: {age}");
  }


  [Test]
  [MatrixDataSource]
  public void ParameterizedFunction([Matrix("x", "y")] string a, [Matrix(0, 1)] int b)
  {
    Console.WriteLine($"a: {a}, b: {b}");
  }
}
