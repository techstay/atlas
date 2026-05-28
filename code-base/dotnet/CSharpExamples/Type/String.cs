#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

StringMethods();
StringInterpolation();
VerbatimString();

static void StringMethods()
{
  string sample = " Hello, World! ";

  Console.WriteLine($"Length: {sample.Length}");
  Console.WriteLine($"Trimmed: '{sample.Trim()}'");
  Console.WriteLine($"Uppercase: {sample.ToUpper()}");
  Console.WriteLine($"Lowercase: {sample.ToLower()}");
  Console.WriteLine($"Substring (7, 5): {sample.Substring(7, 5)}");
  Console.WriteLine($"Replace 'World' with 'C#': {sample.Replace("World", "C#")}");
  Console.WriteLine($"Contains 'Hello': {sample.Contains("Hello")}");

  var parts = sample.Split(',');
  Console.WriteLine($"Split by ',': [{string.Join(" | ", parts)}]");

  _ = "This is an utf8 string"u8;
}

static void StringInterpolation()
{
  string name = "CSharp";
  int year = 2025;
  string message = $"Welcome to {name} programming in the year {year}!";
  Console.WriteLine(message);
}

static void VerbatimString()
{
  string filePath = @"C:\Users\Username\Documents\file.txt";
  Console.WriteLine($"File Path: {filePath}");
}
