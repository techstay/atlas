#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

QueueOperations();

static void QueueOperations()
{
  Queue<string> queue = new();

  queue.Enqueue("First");
  queue.Enqueue("Second");
  queue.Enqueue("Third");

  Console.WriteLine($"Peek: {queue.Peek()}");
  Console.WriteLine($"Count: {queue.Count}");

  Console.WriteLine("All items in the queue:");
  foreach (var item in queue)
  {
    Console.WriteLine(item);
  }

  Console.WriteLine($"Dequeued: {queue.Dequeue()}");

  Console.WriteLine("Items in the queue after dequeue:");
  foreach (var item in queue)
  {
    Console.WriteLine(item);
  }
}
