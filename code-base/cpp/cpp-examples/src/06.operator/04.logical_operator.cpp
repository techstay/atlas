import std;

int main()
{
    // Logical operators
    bool result;

    result = true && false; // logical AND
    std::println("true && false = {}", result);

    result = true || false; // logical OR
    std::println("true || false = {}", result);

    result = !true; // logical NOT
    std::println("!true         = {}", result);

    // Short-circuit evaluation: the right operand is NOT evaluated
    // when the result is already determined by the left operand.
    int i = 0;

    result = false && (i++);                         // AND: left is false, right skipped
    std::println("After false && (i++): i = {}", i); // i still 0

    result = true || (i++);                          // OR: left is true, right skipped
    std::println("After true  || (i++): i = {}", i); // i still 0

    // No short-circuit: left is true, so right is evaluated
    result = true && (i++);
    std::println("After true  && (i++): i = {}", i); // i becomes 1
}
