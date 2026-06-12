import std;

void print_space(std::filesystem::path const& path)
{
    auto info   = std::filesystem::space(path);
    auto to_gib = [](std::uintmax_t bytes) { return bytes / 1024.0 / 1024.0 / 1024.0; };

    std::println("{}", path.string());
    std::println("  capacity:  {:8.2f} GiB", to_gib(info.capacity));

    // `free` is the total free space on the volume, including blocks reserved
    // for the superuser / OS. Regular users cannot always use all of it.
    std::println("  free:      {:8.2f} GiB  (total, including OS-reserved)", to_gib(info.free));

    // `available` is the free space accessible by the current (non-root) user.
    // available <= free; the difference is the OS-reserved portion.
    std::println("  available: {:8.2f} GiB  (usable by current user)", to_gib(info.available));
    std::println();
}

int main()
{
    print_space(std::filesystem::current_path());
    print_space(std::filesystem::temp_directory_path());

    // Calling space() on a non-existent path throws filesystem_error.
    std::error_code ec;
    auto            bad = std::filesystem::space("/nonexistent", ec);
    if (ec) { std::println("space(\"/nonexistent\"): error — {}", ec.message()); }
    else
    {
        std::println("space(\"/nonexistent\"): capacity={}", bad.capacity);
    }
}
