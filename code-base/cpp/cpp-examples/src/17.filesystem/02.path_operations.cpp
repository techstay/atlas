import std;

int main()
{
    auto                  tmp = std::filesystem::temp_directory_path();
    std::filesystem::path p   = tmp / "cpp_demo_test.txt";
    std::filesystem::path p2  = tmp / "cpp_demo_renamed.txt";
    std::filesystem::path dir = tmp / "cpp_demo_dir" / "sub"; // two levels deep

    // ── Existence check ───────────────────────────────────────────────────────
    std::println("exists({}): {}", p.filename().string(), std::filesystem::exists(p));

    // ── Create and inspect ────────────────────────────────────────────────────
    {
        std::ofstream{p} << "Hello from std::filesystem!\n";
    }
    std::println("After write:  exists={}, size={} bytes", std::filesystem::exists(p),
                 std::filesystem::file_size(p));

    // ── Rename / move ─────────────────────────────────────────────────────────
    std::filesystem::rename(p, p2);
    std::println("After rename: {} exists={}, {} exists={}", p.filename().string(),
                 std::filesystem::exists(p), p2.filename().string(), std::filesystem::exists(p2));

    // ── create_directory vs create_directories ────────────────────────────────
    // create_directory: creates exactly ONE directory; parent must exist.
    // create_directories: creates the full path, like `mkdir -p`.
    std::filesystem::create_directories(dir); // creates cpp_demo_dir/sub in one call
    std::println("create_directories: is_directory({})={}", dir.string(),
                 std::filesystem::is_directory(dir));

    // ── copy_file with copy_options ───────────────────────────────────────────
    std::filesystem::path p3 = tmp / "cpp_demo_copy.txt";
    // copy_options::overwrite_existing allows re-running without manual cleanup.
    std::filesystem::copy_file(p2, p3, std::filesystem::copy_options::overwrite_existing);
    std::println("copy_file: {} exists={}", p3.filename().string(), std::filesystem::exists(p3));

    // ── Error-code overload (no exceptions) ───────────────────────────────────
    // Every filesystem function has a noexcept overload accepting std::error_code.
    std::error_code ec;
    std::filesystem::remove("/nonexistent/path/file.txt", ec);
    if (ec) { std::println("remove failed (expected): {}", ec.message()); }

    // ── Cleanup ───────────────────────────────────────────────────────────────
    std::filesystem::remove(p2);
    std::filesystem::remove(p3);
    std::filesystem::remove_all(tmp / "cpp_demo_dir"); // remove_all for non-empty directories
    std::println("Cleaned up.");
}
