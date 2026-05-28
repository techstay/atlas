#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

TypePattern();
RelationalPattern();
ListPattern();

static void TypePattern()
{
  object obj = 42;
  if (obj is int number)
  {
    Console.WriteLine($"The number is {number}");
  }
  else
  {
    Console.WriteLine("The object is not an integer.");
  }
}

static void RelationalPattern()
{
  int score = 100;
  var result = score switch
  {
    >= 0 and <= 60 => "failed",
    > 60 and <= 80 => "good",
    > 80 and < 100 => "very good",
    100 => "perfect",
    _ => "something"
  };

  Console.WriteLine($"The performance is: {result}");
}

static void ListPattern()
{
  int[] list = { 1, 2, 3 };
  Ensure(list is [1, 2, 3], "Exact list pattern should match.");
  Ensure(list is [0 or 1, > 1, > 2], "Relational list pattern should match.");
  Ensure(list is not [> 2, > 3, > 4], "The negative list pattern should not match.");
}

static void Ensure(bool condition, string message)
{
  if (!condition)
  {
    throw new InvalidOperationException(message);
  }
}
