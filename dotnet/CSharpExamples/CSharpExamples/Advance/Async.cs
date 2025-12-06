namespace CSharpExamples.Advance;

class AsyncShowCase
{
  [Test]
  public async Task SimpleAsyncAwait()
  {
    Console.WriteLine("Starting async operation...");
    await Task.Delay(2000);
    Console.WriteLine("Async operation completed.");
  }

  [Test]
  public async Task AsyncWithResult()
  {
    Console.WriteLine("Starting async operation with result...");
    int result = await ComputeSumAsync(5, 10);
    Console.WriteLine($"The sum is: {result}");
    await Assert.That(result).IsEqualTo(15);
  }

  private async Task<int> ComputeSumAsync(int a, int b)
  {
    await Task.Delay(1000);
    return a + b;
  }
}
