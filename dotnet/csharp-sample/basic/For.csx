for (int a = 1; a <= 9; a++)
{
  for (int b = 1; b <= a; b++)
  {
    System.Console.Write($"{b}*{a}={a * b}\t");
  }
  System.Console.WriteLine();
}
