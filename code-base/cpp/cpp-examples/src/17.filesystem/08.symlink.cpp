import std;

// NOTE (Windows): Creating symlinks requires either:
//   - Developer Mode enabled (Settings → Privacy & Security → Developer Mode), or
//   - Administrator privileges.
// On Linux/macOS no special privileges are needed.

int main()
{
    auto tmp     = std::filesystem::temp_directory_path();
    auto target  = tmp / "cpp_symlink_target.txt";
    auto link    = tmp / "cpp_symlink_link.txt";
    auto dirlink = tmp / "cpp_symlink_dirlink";
    auto dir     = tmp / "cpp_symlink_dir";

    // ── Setup ─────────────────────────────────────────────────────────────────
    {
        std::ofstream{target} << "I am the target file.\n";
    }
    std::filesystem::create_directory(dir);

    // ── create_symlink / create_directory_symlink ─────────────────────────────
    std::error_code ec;
    std::filesystem::create_symlink(target, link, ec);
    if (ec)
    {
        std::println("create_symlink failed: {}", ec.message());
        std::println("(On Windows, enable Developer Mode or run as Administrator.)");
        std::filesystem::remove(target);
        std::filesystem::remove_all(dir);
        return 1;
    }
    std::filesystem::create_directory_symlink(dir, dirlink);

    // ── Inspecting symlinks ───────────────────────────────────────────────────
    // status()         follows the symlink → reports the TARGET's type.
    // symlink_status() does NOT follow → reports symlink itself as file_type::symlink.
    std::println("link path: {}", link.string());
    std::println("  is_symlink (symlink_status): {}",
                 std::filesystem::is_symlink(std::filesystem::symlink_status(link)));
    std::println("  is_regular (status, follows): {}", std::filesystem::is_regular_file(link));

    // read_symlink() returns the path the symlink points to (not resolved).
    auto dest = std::filesystem::read_symlink(link);
    std::println("  -> points to: {}", dest.string());

    // canonical() resolves the full absolute path, following all symlinks.
    auto canon = std::filesystem::canonical(link);
    std::println("  canonical:    {}", canon.string());

    std::println();

    // ── Directory symlink ─────────────────────────────────────────────────────
    std::println("dirlink: {}", dirlink.string());
    std::println("  is_symlink: {}",
                 std::filesystem::is_symlink(std::filesystem::symlink_status(dirlink)));
    std::println("  is_directory (follows): {}", std::filesystem::is_directory(dirlink));

    // ── Cleanup ───────────────────────────────────────────────────────────────
    std::filesystem::remove(link);
    std::filesystem::remove(dirlink);
    std::filesystem::remove(target);
    std::filesystem::remove_all(dir);
    std::println("\nCleaned up.");
}
