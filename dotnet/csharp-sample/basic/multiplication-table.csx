using Internal;

for (int i = 1; i <= 9; i++)
{
  for (int j = 1; j <= i; j++)
  {
    Console.Write($"{j}*{i}={j * i}\t");
  }
  Console.WriteLine();
}
