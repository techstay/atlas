import std;

int main()
{
    // PROBLEM: shared_ptr in both directions creates a cycle.
    {
        struct Node
        {
            std::string           name;
            std::shared_ptr<Node> next;
            std::shared_ptr<Node> prev;
            explicit Node(std::string n) : name(std::move(n)) { std::println("ctor: {}", name); }
            ~Node() { std::println("dtor: {}", name); }
        };

        auto a  = std::make_shared<Node>("leaky A");
        auto b  = std::make_shared<Node>("leaky B");
        a->next = b;
        b->prev = a;
    } // no dtor printed: a and b still own each other

    // FIX: make the back link weak_ptr so it does not own.
    {
        struct Node
        {
            std::string           name;
            std::shared_ptr<Node> next;
            std::weak_ptr<Node>   prev;
            explicit Node(std::string n) : name(std::move(n)) { std::println("ctor: {}", name); }
            ~Node() { std::println("dtor: {}", name); }
        };

        auto a  = std::make_shared<Node>("fixed A");
        auto b  = std::make_shared<Node>("fixed B");
        a->next = b;
        b->prev = a;
    } // both dtors printed
}
