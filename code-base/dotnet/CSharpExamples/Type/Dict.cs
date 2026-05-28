#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

DictionaryOperations();

static void DictionaryOperations()
{
  Dictionary<string, int> ages = new()
  {
    { "Alice", 30 },
    { "Bob", 25 },
    { "Charlie", 35 }
  };

  ages["David"] = 28;
  ages.Add("Eve", 22);

  Console.WriteLine($"Alice's age: {ages["Alice"]}");
  Console.WriteLine($"Count: {ages.Count}");

  Console.WriteLine("All entries:");
  foreach (var kvp in ages)
  {
    Console.WriteLine($"{kvp.Key}: {kvp.Value}");
  }

  ages.Remove("Bob");

  Console.WriteLine("Entries after removal:");
  foreach (var kvp in ages)
  {
    Console.WriteLine($"{kvp.Key}: {kvp.Value}");
  }
}
