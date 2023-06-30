for (int i = 0; i < 10; i++)
{
  if (i == 5)
  {
    break;
  }
  System.Console.Write($"{i} ");
}
System.Console.WriteLine();

for (int i = 0; i < 10; i++)
{
  if (i == 5)
  {
    continue;
  }
  System.Console.Write($"{i} ");
}
System.Console.WriteLine();
