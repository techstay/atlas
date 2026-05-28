#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

StackOperations();

static void StackOperations()
{
  Stack<string> stack = new();

  stack.Push("First");
  stack.Push("Second");
  stack.Push("Third");

  Console.WriteLine($"Peek: {stack.Peek()}");
  Console.WriteLine($"Count: {stack.Count}");

  Console.WriteLine("All items in the stack:");
  foreach (var item in stack)
  {
    Console.WriteLine(item);
  }

  Console.WriteLine($"Popped: {stack.Pop()}");

  Console.WriteLine("Items in the stack after pop:");
  foreach (var item in stack)
  {
    Console.WriteLine(item);
  }
}
