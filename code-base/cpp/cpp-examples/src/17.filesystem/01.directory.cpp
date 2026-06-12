import std;

int main()
{
    // ── Path component decomposition ──────────────────────────────────────────
    // A representative path makes every component meaningful.
    // (The path doesn't need to exist on disk for decomposition.)
#ifdef _WIN32
    std::filesystem::path p{"C:\\Windows\\System32\\drivers\\etc\\hosts"};
#else
    std::filesystem::path p{"/usr/local/lib/libfoo.so.2"};
#endif
    std::println("Path: {}", p.string());
    std::println("  root_name:      '{}'", p.root_name().string());
    std::println("  root_directory: '{}'", p.root_directory().string());
    std::println("  root_path:      '{}'", p.root_path().string());
    std::println("  relative_path:  '{}'", p.relative_path().string());
    std::println("  parent_path:    '{}'", p.parent_path().string());
    std::println("  filename:       '{}'", p.filename().string());
    std::println("  stem:           '{}'", p.stem().string()); // filename without last extension
    std::println("  extension:      '{}'", p.extension().string());
    std::println();

    // ── Directory listing with metadata ──────────────────────────────────────
    auto dir = std::filesystem::current_path();
    std::println("Listing (first 10): {}", dir.string());

    int count = 0;
    for (auto const& entry : std::filesystem::directory_iterator(dir))
    {
        // last_write_time() returns file_time_type (a chrono::time_point).
        // It is directly formattable in C++20 via std::formatter<chrono::time_point>.
        auto ftime = entry.last_write_time();
        std::println("  [{}] {:30}  modified: {}", entry.is_directory() ? "DIR " : "FILE",
                     entry.path().filename().string(), ftime);
        if (++count >= 10) { break; }
    }
}
