namespace CSharpExamples.Basic;

public class CommentShowCase()
{
  [Test]
  public async Task Comment()
  {
    var x = 42;
    // This is a single line comment.
    // Comments are ignored by the compiler.
    // x = 64;

    /* This is a multi-line comment.
     * It can span multiple lines.
     */

    Console.WriteLine("Hello, World!");

    await Assert.That(x).IsEqualTo(42);
  }
}
