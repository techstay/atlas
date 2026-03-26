#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

SimpleFunction();
MultipleParametersFunction("Alice", 32);
DefaultParameterFunction("John Doe", 32);
DefaultParameterFunction("Alice");
DefaultParameterFunction();

foreach (var a in new[] { "x", "y" })
{
  foreach (var b in new[] { 0, 1 })
  {
    ParameterizedFunction(a, b);
  }
}

static void SimpleFunction()
{
  Console.WriteLine("This is a simple function.");
}

static void MultipleParametersFunction(string name, int age)
{
  Console.WriteLine($"Name: {name}, Age: {age}");
}

static void DefaultParameterFunction(string name = "John Doe", int age = 32)
{
  Console.WriteLine($"Name: {name}, Age: {age}");
}

static void ParameterizedFunction(string a, int b)
{
  Console.WriteLine($"a: {a}, b: {b}");
}
