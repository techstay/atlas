import std;

// Every std::filesystem function has two overload families:
//
//   1. Exception-based (default):
//        auto sz = std::filesystem::file_size(p);
//        Throws std::filesystem::filesystem_error on failure.
//
//   2. Error-code-based (noexcept):
//        std::error_code ec;
//        auto sz = std::filesystem::file_size(p, ec);
//        Never throws; check ec afterwards.
//
// filesystem_error carries:
//   .what()  – human-readable message (includes path info)
//   .path1() – the primary path involved
//   .path2() – the secondary path (for two-path operations like rename)
//   .code()  – the underlying std::error_code

int main()
{
    std::filesystem::path bad{"/nonexistent/path/file.txt"};

    // ── Pattern 1: exception-based ────────────────────────────────────────────
    try
    {
        auto sz = std::filesystem::file_size(bad); // throws
        std::println("size: {}", sz);
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::println("[exception] what:  {}", ex.what());
        std::println("[exception] path1: {}", ex.path1().string());
        std::println("[exception] code:  {} ({})", ex.code().value(), ex.code().message());
    }
    std::println();

    // ── Pattern 2: error-code-based (noexcept) ────────────────────────────────
    {
        std::error_code ec;
        auto            sz = std::filesystem::file_size(bad, ec);
        if (ec) { std::println("[error_code] {}: {}", ec.value(), ec.message()); }
        else
        {
            std::println("[error_code] size: {}", sz);
        }
    }
    std::println();

    // ── Two-path operation: rename ────────────────────────────────────────────
    {
        std::error_code ec;
        std::filesystem::rename("/no/src.txt", "/no/dst.txt", ec);
        if (ec) { std::println("[rename error] {}", ec.message()); }
    }

    // ── Guideline ─────────────────────────────────────────────────────────────
    // • Use the exception form in application code where errors are unexpected.
    // • Use the error_code form in hot loops, destructors, or when performance
    //   matters (no stack unwinding overhead).
}
