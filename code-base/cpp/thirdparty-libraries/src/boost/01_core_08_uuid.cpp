#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <print>
#include <string>

int main()
{
    // random UUID
    boost::uuids::random_generator gen;
    auto                           uuid1 = gen();
    std::println("random UUID: {}", uuid1);

    // nil UUID
    boost::uuids::nil_uuid();
    std::println("nil UUID: {}", boost::uuids::to_string(boost::uuids::nil_uuid()));

    // string generator
    boost::uuids::string_generator sgen;
    auto                           uuid2 = sgen("550e8400-e29b-41d4-a716-446655440000");
    std::println("parsed UUID: {}", uuid2);

    // equality
    std::println("uuid1 == uuid1: {}", uuid1 == uuid1);
    std::println("uuid1 == uuid2: {}", uuid1 == uuid2);

    // to/from string
    std::string str = boost::uuids::to_string(uuid1);
    std::println("uuid1 string: {}", str);

    return 0;
}
