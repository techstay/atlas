import std;

// Helper: pretty-print a perms bitmask in rwxrwxrwx style.
std::string perms_to_string(std::filesystem::perms p)
{
    using P  = std::filesystem::perms;
    auto bit = [&](P mask, char c) { return (p & mask) != P::none ? c : '-'; };
    return {
        bit(P::owner_read, 'r'),  bit(P::owner_write, 'w'),  bit(P::owner_exec, 'x'),
        bit(P::group_read, 'r'),  bit(P::group_write, 'w'),  bit(P::group_exec, 'x'),
        bit(P::others_read, 'r'), bit(P::others_write, 'w'), bit(P::others_exec, 'x'),
    };
}

int main()
{
    // Create a temp file and directory to inspect.
    auto tmp  = std::filesystem::temp_directory_path();
    auto file = tmp / "cpp_status_demo.txt";
    auto dir  = tmp / "cpp_status_demo_dir";

    {
        std::ofstream{file} << "status demo\n";
    }
    std::filesystem::create_directory(dir);

    // ── file_status and file_type ─────────────────────────────────────────────
    // status() follows symlinks; symlink_status() does not.
    for (auto const& path : {file, dir})
    {
        auto st   = std::filesystem::status(path);
        auto type = st.type();

        std::string type_name;
        switch (type)
        {
        case std::filesystem::file_type::regular:
            type_name = "regular";
            break;
        case std::filesystem::file_type::directory:
            type_name = "directory";
            break;
        case std::filesystem::file_type::symlink:
            type_name = "symlink";
            break;
        case std::filesystem::file_type::not_found:
            type_name = "not_found";
            break;
        default:
            type_name = "other";
            break;
        }

        std::println("{}", path.filename().string());
        std::println("  type:        {}", type_name);
        std::println("  is_regular:  {}", std::filesystem::is_regular_file(st));
        std::println("  is_dir:      {}", std::filesystem::is_directory(st));

#ifndef _WIN32
        // permissions() returns a perms bitmask (POSIX rwxrwxrwx).
        // On Windows this is a simplified model (only owner_write is meaningful).
        std::println("  permissions: {}", perms_to_string(st.permissions()));
#endif
        std::println();
    }

    // ── Modifying permissions ─────────────────────────────────────────────────
#ifndef _WIN32
    // Add owner execute bit, leave others unchanged.
    std::filesystem::permissions(file, std::filesystem::perms::owner_exec,
                                 std::filesystem::perm_options::add);
    std::println("After adding exec: {}",
                 perms_to_string(std::filesystem::status(file).permissions()));

    // Remove the bit again.
    std::filesystem::permissions(file, std::filesystem::perms::owner_exec,
                                 std::filesystem::perm_options::remove);
#endif

    // ── Cleanup ───────────────────────────────────────────────────────────────
    std::filesystem::remove(file);
    std::filesystem::remove(dir);
    std::println("Cleaned up.");
}
