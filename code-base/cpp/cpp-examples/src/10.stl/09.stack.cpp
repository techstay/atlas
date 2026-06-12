import std;

int main()
{
    // std::stack defaults to using std::deque as the underlying container
    std::stack<int> st;
    st.push(10);
    st.push(20);
    std::println("stack top: {}", st.top());
    st.pop();
    std::println("stack top after pop: {}", st.top());

    // Custom underlying container for std::stack
    std::stack<int, std::vector<int>> st_vec;
    st_vec.push(100);
    st_vec.push(200);
    std::println("stack (vector) top: {}", st_vec.top());

    std::stack<int, std::list<int>> st_list;
    st_list.push(1000);
    st_list.push(2000);
    std::println("stack (list) top: {}", st_list.top());
}
