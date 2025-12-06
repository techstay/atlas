namespace CSharpExamples.Type;

class DictShowCase
{
  [Test]
  public void DictionaryOperations()
  {
    // create a dictionary
    Dictionary<string, int> ages = new Dictionary<string, int>
    {
      { "Alice", 30 },
      { "Bob", 25 },
      { "Charlie", 35 }
    };

    // add elements
    ages["David"] = 28;
    ages.Add("Eve", 22);

    // access elements
    Console.WriteLine($"Alice's age: {ages["Alice"]}");
    Console.WriteLine($"Count: {ages.Count}");

    // iterate through the dictionary
    Console.WriteLine("All entries:");
    foreach (var kvp in ages)
    {
      Console.WriteLine($"{kvp.Key}: {kvp.Value}");
    }

    // remove elements
    ages.Remove("Bob");

    Console.WriteLine("Entries after removal:");
    foreach (var kvp in ages)
    {
      Console.WriteLine($"{kvp.Key}: {kvp.Value}");
    }
  }
}
