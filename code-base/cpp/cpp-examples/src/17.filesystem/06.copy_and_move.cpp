import std;

int main()
{
    auto tmp = std::filesystem::temp_directory_path();
    auto src = tmp / "cpp_copy_src.txt";
    auto dst = tmp / "cpp_copy_dst.txt";
    auto dir = tmp / "cpp_copy_demo";

    {
        std::ofstream{src} << "copy demo content\n";
    }
    std::filesystem::create_directory(dir);

    // ── copy_file ─────────────────────────────────────────────────────────────
    // Default: throws if destination already exists.
    std::filesystem::copy_file(src, dst);
    std::println("copy_file: {} -> {}  (size={})", src.filename().string(), dst.filename().string(),
                 std::filesystem::file_size(dst));

    // copy_options::overwrite_existing — silently replaces destination.
    // copy_options::skip_existing      — silently skips if destination exists.
    // copy_options::update_existing    — copies only if source is newer.
    std::filesystem::copy_file(src, dst, std::filesystem::copy_options::overwrite_existing);
    std::println("overwrite_existing: ok");

    // ── copy (directory, recursive) ───────────────────────────────────────────
    auto src_dir = tmp / "cpp_copy_src_dir";
    auto dst_dir = tmp / "cpp_copy_dst_dir";
    std::filesystem::create_directories(src_dir / "sub");
    {
        std::ofstream{src_dir / "a.txt"} << "a";
    }
    {
        std::ofstream{src_dir / "sub" / "b.txt"} << "b";
    }

    // copy_options::recursive copies the whole subtree.
    std::filesystem::copy(src_dir, dst_dir, std::filesystem::copy_options::recursive);
    std::println("Recursive copy:");
    for (auto const& e : std::filesystem::recursive_directory_iterator(dst_dir))
    {
        std::println("  {}", e.path().lexically_relative(tmp).string());
    }

    // ── rename (also works across directories on the same volume) ─────────────
    auto renamed = tmp / "cpp_copy_renamed.txt";
    std::filesystem::rename(dst, renamed);
    std::println("rename: {} exists={}", renamed.filename().string(),
                 std::filesystem::exists(renamed));

    // ── Cleanup ───────────────────────────────────────────────────────────────
    std::filesystem::remove(src);
    std::filesystem::remove(renamed);
    std::filesystem::remove_all(dir);
    std::filesystem::remove_all(src_dir);
    std::filesystem::remove_all(dst_dir);
    std::println("Cleaned up.");
}
