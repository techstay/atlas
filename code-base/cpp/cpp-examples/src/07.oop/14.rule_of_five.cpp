import std;

// Rule of Five: if a class needs a custom destructor, copy constructor,
// copy assignment, move constructor, or move assignment, it probably
// needs all five. This is about managing owned resources correctly.
//
// Rule of Three (pre-C++11): destructor, copy constructor, copy assignment.
// Rule of Five (C++11+): adds move constructor and move assignment.
// Rule of Zero: prefer composing from types that already follow the Rule of Five.

class Buffer
{
private:
    int*        data_;
    std::size_t size_;

public:
    // Constructor
    explicit Buffer(std::size_t size) : data_(new int[size]{}), size_(size)
    { std::println("Buffer({}) constructed", size); }

    // 1. Destructor — release owned resource
    ~Buffer()
    {
        delete[] data_;
        std::println("Buffer destroyed");
    }

    // 2. Copy constructor — deep copy
    Buffer(const Buffer& other) : data_(new int[other.size_]), size_(other.size_)
    {
        std::copy(other.data_, other.data_ + size_, data_);
        std::println("Buffer copied (size={})", size_);
    }

    // 3. Copy assignment — deep copy, handle self-assignment
    Buffer& operator=(const Buffer& other)
    {
        std::println("Buffer copy-assigned (size={})", other.size_);
        if (this != &other)
        {
            delete[] data_; // release old resource
            size_ = other.size_;
            data_ = new int[size_];
            std::copy(other.data_, other.data_ + size_, data_);
        }
        return *this;
    }

    // 4. Move constructor — transfer ownership, leave source empty
    Buffer(Buffer&& other) noexcept : data_(other.data_), size_(other.size_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        std::println("Buffer moved (size={})", size_);
    }

    // 5. Move assignment — transfer ownership, handle self-assignment
    Buffer& operator=(Buffer&& other) noexcept
    {
        std::println("Buffer move-assigned (size={})", other.size_);
        if (this != &other)
        {
            delete[] data_;
            data_       = other.data_;
            size_       = other.size_;
            other.data_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    // Accessors
    std::size_t size() const { return size_; }
    int&        operator[](std::size_t i) { return data_[i]; }
    const int&  operator[](std::size_t i) const { return data_[i]; }
};

// Rule of Zero: no custom destructor/copy/move needed
// std::vector handles all resource management automatically
class BetterBuffer
{
    std::vector<int> data_;

public:
    explicit BetterBuffer(std::size_t size) : data_(size) {}
    std::size_t size() const { return data_.size(); }
    int&        operator[](std::size_t i) { return data_[i]; }
};

int main()
{
    std::println("=== Rule of Five: Buffer ===\n");

    Buffer b1(5);
    b1[0] = 10;
    b1[1] = 20;

    // Copy constructor
    Buffer b2 = b1;
    std::println("b1[0]={}, b2[0]={}", b1[0], b2[0]);

    // Move constructor
    Buffer b3 = std::move(b1);
    std::println("b1 size after move: {}", b1.size()); // 0

    // Copy assignment
    Buffer b4(3);
    b4 = b2;

    // Move assignment
    Buffer b5(1);
    b5 = std::move(b2);

    std::println("\n=== Rule of Zero: BetterBuffer ===");
    BetterBuffer bb1(5);
    BetterBuffer bb2 = bb1;            // compiler-generated copy
    BetterBuffer bb3 = std::move(bb1); // compiler-generated move
    std::println("Rule of Zero: no manual resource management needed!");
}