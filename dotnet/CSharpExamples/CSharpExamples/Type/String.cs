namespace CSharpExamples.Type;

class StringShowCase
{
  [Test]
  public void StringMethods()
  {
    string sample = " Hello, World! ";

    // Length
    Console.WriteLine($"Length: {sample.Length}");

    // Trim
    Console.WriteLine($"Trimmed: '{sample.Trim()}'");

    // ToUpper and ToLower
    Console.WriteLine($"Uppercase: {sample.ToUpper()}");
    Console.WriteLine($"Lowercase: {sample.ToLower()}");

    // Substring
    Console.WriteLine($"Substring (7, 5): {sample.Substring(7, 5)}");

    // Replace
    Console.WriteLine($"Replace 'World' with 'C#': {sample.Replace("World", "C#")}");

    // Contains
    Console.WriteLine($"Contains 'Hello': {sample.Contains("Hello")}");

    // Split
    var parts = sample.Split(',');
    Console.WriteLine($"Split by ',': [{string.Join(" | ", parts)}]");

    // Utf8 strings
    _ = "This is an utf8 string"u8;
  }

  [Test]
  public void StringInterpolation()
  {
    string name = "CSharp";
    int year = 2025;

    // Using string interpolation
    string message = $"Welcome to {name} programming in the year {year}!";
    Console.WriteLine(message);
  }

  [Test]
  public void VerbatimString()
  {
    string filePath = @"C:\Users\Username\Documents\file.txt";
    Console.WriteLine($"File Path: {filePath}");
  }
}
