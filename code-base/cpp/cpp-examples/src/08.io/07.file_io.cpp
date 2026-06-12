import std;

int main()
{
    auto temp_dir  = std::filesystem::temp_directory_path();
    auto temp_file = temp_dir / "hello.txt";

    std::println("Temp path: {}", temp_file.string());

    std::ofstream out(temp_file, std::ios::out);
    std::println(out, "Hello techstay!");
    out.close();
    std::println("Writing finished.");

    std::ifstream in(temp_file, std::ios::in);
    std::string   content((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::println("Start reading:\n{}", content);

    // Clean up the temporary file.
    std::filesystem::remove(temp_file);
}
