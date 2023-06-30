// nullable types
double? number = 3.14;
System.Console.WriteLine(number);

// allow value types to be nullable
number = null;
System.Console.WriteLine(number ?? -1);
System.Console.WriteLine(number.GetValueOrDefault(-1));

number = number ?? 3.14159;
System.Console.WriteLine(number);

// check a type is nullable or not
System.Console.WriteLine($"HasValue: {number.HasValue}");
