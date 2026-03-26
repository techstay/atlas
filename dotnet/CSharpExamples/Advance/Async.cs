#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

await SimpleAsyncAwait();
await AsyncWithResult();

static async Task SimpleAsyncAwait()
{
  Console.WriteLine("Starting async operation...");
  await Task.Delay(2000);
  Console.WriteLine("Async operation completed.");
}

static async Task AsyncWithResult()
{
  Console.WriteLine("Starting async operation with result...");
  var result = await ComputeSumAsync(5, 10);
  Console.WriteLine($"The sum is: {result}");
  Ensure(result == 15, "The async sum should be 15.");
}

static async Task<int> ComputeSumAsync(int a, int b)
{
  await Task.Delay(1000);
  return a + b;
}

static void Ensure(bool condition, string message)
{
  if (!condition)
  {
    throw new InvalidOperationException(message);
  }
}
