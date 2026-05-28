#:property TargetFramework=net10.0
#:property PublishAot=false
#:property SelfContained=false
#:property UseCurrentRuntimeIdentifier=false

var x = 42;
// This is a single line comment.
// Comments are ignored by the compiler.
// x = 64;

/* This is a multi-line comment.
 * It can span multiple lines.
 */

Console.WriteLine("Hello, World!");
Ensure(x == 42, "The comment example should keep x unchanged.");

static void Ensure(bool condition, string message)
{
  if (!condition)
  {
    throw new InvalidOperationException(message);
  }
}
