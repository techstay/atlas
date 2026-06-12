import std;

struct Record
{
    int    id;
    double score;
};

int main()
{
    std::filesystem::path file = std::filesystem::temp_directory_path() / "record.bin";
    Record                out_record{7, 98.5};

    // Write raw bytes with ofstream::write().
    std::ofstream out(file, std::ios::binary);
    out.write(reinterpret_cast<char const*>(&out_record), sizeof(out_record));
    out.close();

    Record in_record{};

    // Read raw bytes with ifstream::read().
    std::ifstream in(file, std::ios::binary);
    in.read(reinterpret_cast<char*>(&in_record), sizeof(in_record));
    in.close();

    std::println("read id={}, score={}", in_record.id, in_record.score);
    std::filesystem::remove(file);
}
