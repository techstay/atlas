namespace CSharpExamples.Type;

class QueueShowCase
{
  [Test]
  public void QueueOperations()
  {
    // create a queue
    Queue<string> queue = new();

    // enqueue elements
    queue.Enqueue("First");
    queue.Enqueue("Second");
    queue.Enqueue("Third");

    // access elements
    Console.WriteLine($"Peek: {queue.Peek()}");
    Console.WriteLine($"Count: {queue.Count}");

    // iterate through the queue
    Console.WriteLine("All items in the queue:");
    foreach (var item in queue)
    {
      Console.WriteLine(item);
    }

    // dequeue elements
    Console.WriteLine($"Dequeued: {queue.Dequeue()}");

    Console.WriteLine("Items in the queue after dequeue:");
    foreach (var item in queue)
    {
      Console.WriteLine(item);
    }
  }
}
