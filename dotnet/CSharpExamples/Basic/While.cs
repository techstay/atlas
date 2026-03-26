#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

WhileLoop();
DoWhileLoop();

static void WhileLoop()
{
  var count = 1;

  while (count <= 5)
  {
    Console.WriteLine($"Count is: {count}");
    count++;
  }
}

static void DoWhileLoop()
{
  var count = 1;

  do
  {
    Console.WriteLine($"Count is: {count}");
    count++;
  } while (count <= 5);
}
