namespace CSharpExamples.Type;

class StackShowCase
{
  [Test]
  public void StackOperations()
  {
    // create a stack
    Stack<string> stack = new();

    // push elements
    stack.Push("First");
    stack.Push("Second");
    stack.Push("Third");

    // access elements
    Console.WriteLine($"Peek: {stack.Peek()}");
    Console.WriteLine($"Count: {stack.Count}");

    // iterate through the stack
    Console.WriteLine("All items in the stack:");
    foreach (var item in stack)
    {
      Console.WriteLine(item);
    }

    // pop elements
    Console.WriteLine($"Popped: {stack.Pop()}");

    Console.WriteLine("Items in the stack after pop:");
    foreach (var item in stack)
    {
      Console.WriteLine(item);
    }
  }
}
