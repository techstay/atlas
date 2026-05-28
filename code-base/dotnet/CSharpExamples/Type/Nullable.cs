#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

double? number = 3.14;
Console.WriteLine(number);

number = null;
Console.WriteLine(number ?? -1);
Console.WriteLine(number.GetValueOrDefault(-1));

number ??= 3.14159;
Console.WriteLine(number);
Console.WriteLine($"HasValue: {number.HasValue}");
