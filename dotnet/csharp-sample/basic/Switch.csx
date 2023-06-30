var score = 88;
switch (score)
{
  case 0:
    System.Console.WriteLine("oh my god");
    break;
  case < 60:
    System.Console.WriteLine("failed");
    break;
  // pattern matching
  case >= 60 and < 80:
    System.Console.WriteLine("passed");
    break;
  case >= 80 and < 100 when score != 88:
    System.Console.WriteLine("very good");
    break;
  case 88:
    System.Console.WriteLine("nice score!");
    break;
  case 100:
    System.Console.WriteLine("perfect");
    break;
}
