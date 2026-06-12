import std;

int main()
{
    // Ternary operator: condition ? value_if_true : value_if_false
    int         marks{80};
    std::string result = marks >= 60 ? "passed" : "failed";
    std::println("marks = {}, result = {}", marks, result);

    // Nested ternary
    int         score{75};
    std::string grade = score >= 90 ? "A" : score >= 80 ? "B" : score >= 60 ? "C" : "F";
    std::println("score = {}, grade = {}", score, grade);
}
