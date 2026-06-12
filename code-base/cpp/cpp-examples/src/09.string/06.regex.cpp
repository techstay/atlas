import std;

int main()
{
    std::string email = "user@example.com";
    std::regex  email_pattern(R"([\w.%+-]+@[\w.-]+\.[A-Za-z]{2,})");

    // regex_match requires the whole string to match.
    std::println("email match: {}", std::regex_match(email, email_pattern));
    std::println("email match: {}", std::regex_match("user@@example.com", email_pattern));

    std::string text = "Call me at 555-123-4567 tomorrow.";
    std::regex  phone_pattern(R"(\d{3}-\d{3}-\d{4})");
    std::smatch match;

    // regex_search finds a matching substring.
    if (std::regex_search(text, match, phone_pattern))
    {
        std::println("phone found: {}", match.str());
    }

    // regex_replace rewrites all matching substrings.
    std::string hidden = std::regex_replace(text, phone_pattern, "[phone]");
    std::println("redacted: {}", hidden);
}
