int Calc(int a, int b) => a / b;

// exceptions
try
{
  int c = Calc(1, 0);
}
catch (ArithmeticException e)
{
  System.Console.WriteLine($"arithmetic exception: {e.Message}");
}
catch (InvalidOperationException e)
{
  System.Console.WriteLine(e.StackTrace);
  // rethrow exceptions
  throw;
}
finally
{
  System.Console.WriteLine("always executed");
}

// when clause
try
{
  int c = Calc(1, 0);
}
catch (Exception e) when (e is ArithmeticException || e is DivideByZeroException)
{
  System.Console.WriteLine(e.Message);
}
