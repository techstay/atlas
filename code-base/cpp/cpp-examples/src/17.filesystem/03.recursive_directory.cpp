import std;

// Build a small, self-contained directory tree so the demo is reproducible
// regardless of the working directory.
std::filesystem::path setup_tree()
{
    auto root = std::filesystem::temp_directory_path() / "cpp_fs_demo";
    std::filesystem::remove_all(root); // clean up any previous run

    std::filesystem::create_directories(root / "src" / "utils");
    std::filesystem::create_directories(root / "include");
    std::filesystem::create_directories(root / "build");

    for (auto const& f : {
             root / "src" / "main.cpp",
             root / "src" / "utils" / "helper.cpp",
             root / "src" / "utils" / "helper.hpp",
             root / "include" / "api.hpp",
             root / "README.md",
         })
    {
        std::ofstream{f}; // create empty file
    }

    return root;
}

int main()
{
    auto root = setup_tree();
    std::println("Recursive tree from: {}\n", root.string());

    // directory_options::skip_permission_denied prevents exceptions when
    // the iterator encounters directories the user cannot read.
    using rdi = std::filesystem::recursive_directory_iterator;
    auto opts = std::filesystem::directory_options::skip_permission_denied;

    for (auto it = rdi(root, opts); it != rdi(); ++it)
    {
        auto const& entry = *it;
        int         depth = it.depth();

        // Indent by depth to visualise the tree structure.
        std::string indent(depth * 2, ' ');

        if (entry.is_directory())
        {
            std::println("{}[{}]/", indent, entry.path().filename().string());
        }
        else
        {
            // disable_recursion_pending() can be called inside the loop to
            // skip descending into the current directory on the next iteration.
            std::println("{}{} ({} bytes)", indent, entry.path().filename().string(),
                         entry.file_size());
        }
    }

    std::filesystem::remove_all(root);
    std::println("\nCleaned up.");
}
