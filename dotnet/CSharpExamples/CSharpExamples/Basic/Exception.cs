namespace CSharpExamples.Basic;

class ExceptionShowCase
{
  [Test]
  public void TryCatchExample()
  {
    try
    {
      var numerator = 10;
      var denominator = 0;
      var result = numerator / denominator;
      Console.WriteLine($"Result: {result}");
    }
    catch (DivideByZeroException ex)
    {
      Console.WriteLine("Error: Cannot divide by zero.");
      Console.WriteLine($"Exception Message: {ex.Message}");
    }
  }

  [Test]
  public void FinallyExample()
  {
    try
    {
      Console.WriteLine("Executing try block.");
      // Simulate some operation
    }
    catch (Exception ex)
    {
      Console.WriteLine($"Caught an exception: {ex.Message}");
    }
    finally
    {
      Console.WriteLine("Executing finally block. Cleanup can be done here.");
    }
  }

  static int Divide(int a, int b) => a / b;
  [Test]
  public async Task ThrowExample()
  {

    await Assert.That(() =>
    {
      try
      {
        var result = Divide(10, 0);
        Console.WriteLine($"Result: {result}");

      }
      catch (DivideByZeroException ex)
      {
        Console.WriteLine("Caught exception: " + ex.Message);
        throw;
      }
    }).Throws<DivideByZeroException>();

  }

  [Test]
  public void WhenClause()
  {
    var number = 0;
    try
    {
      var result = Divide(10, number);
      Console.WriteLine($"10 divided by {number} is {result}");
    }
    catch (Exception ex) when (ex is ArithmeticException || ex is DivideByZeroException)
    {
      Console.WriteLine($"Caught an exception {number}: {ex.Message}");
    }

  }
}
