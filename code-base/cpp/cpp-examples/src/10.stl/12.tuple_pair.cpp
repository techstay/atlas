import std;

int main()
{
    // std::pair with explicit template arguments
    std::pair<std::string, int> item{"apple", 3};
    std::println("pair: {} = {}", item.first, item.second);

    auto [name, count] = item;
    std::println("structured pair: {} {}", name, count);

    // Since C++17, std::tuple supports CTAD (class template argument deduction)
    // Pre-C++17: use std::make_tuple for automatic type deduction
    auto info = std::tuple{std::string{"Bob"}, 42, 98.5};
    std::println("tuple: {}, {}, {}", std::get<0>(info), std::get<1>(info), std::get<2>(info));
    std::println("tuple size: {}", std::tuple_size<decltype(info)>::value);

    auto [user, age, score] = info;
    std::println("structured tuple: {} {} {}", user, age, score);

    // std::pair also supports CTAD; pre-C++17: use std::make_pair
    std::string city;
    int         zip{};
    std::tie(city, zip) = std::pair{"Paris", 75000};
    std::println("tie: {} {}", city, zip);

    auto merged = std::tuple_cat(item, info, std::tuple{city});
    std::println("tuple_cat size: {}", std::tuple_size<decltype(merged)>::value);

    // Use std::apply with a fold expression to print all elements of the merged tuple
    std::apply(
        [](const auto&... args)
        {
            std::print("merged tuple: ");
            std::size_t i = 0;
            ((std::print("{}{}", args, (++i < sizeof...(args) ? ", " : "")), ...));
            std::println("");
        },
        merged);

    // std::tuple_element and std::tuple_element_t (type extraction from tuple)
    using first_type = std::tuple_element_t<0, decltype(info)>;
    static_assert(std::is_same_v<first_type, std::string>);

    std::tuple_element<1, decltype(info)>::type age_value = std::get<1>(info);
    std::println("age (type extracted): {}", age_value);

    // std::make_from_tuple (C++17) — construct an object from a tuple
    struct Product
    {
        std::string name;
        double      price;
        int         quantity;
        Product(const std::string& n, double p, int q) : name(n), price(p), quantity(q) {}
    };

    auto product_tuple = std::tuple{"Laptop", 999.99, 10};
    auto laptop        = std::make_from_tuple<Product>(product_tuple);
    std::println("Product: {} (${:.2f} x {})", laptop.name, laptop.price, laptop.quantity);
}
