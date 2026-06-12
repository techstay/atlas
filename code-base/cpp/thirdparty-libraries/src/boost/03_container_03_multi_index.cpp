#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index_container.hpp>
#include <print>
#include <string>

namespace mi = boost::multi_index;

struct Employee
{
    int         id;
    std::string name;
    int         dept;
};

struct by_id
{
};
struct by_dept
{
};
struct by_name
{
};

using EmployeeSet = mi::multi_index_container<
    Employee,
    mi::indexed_by<
        mi::ordered_unique<mi::tag<by_id>, mi::member<Employee, int, &Employee::id>>,
        mi::ordered_non_unique<mi::tag<by_dept>, mi::member<Employee, int, &Employee::dept>>,
        mi::hashed_unique<mi::tag<by_name>, mi::member<Employee, std::string, &Employee::name>>>>;

int main()
{
    EmployeeSet emps;
    emps.insert({1, "Alice", 10});
    emps.insert({2, "Bob", 20});
    emps.insert({3, "Charlie", 10});

    // by id (index 0)
    auto& by_id_idx = emps.get<by_id>();
    auto  it        = by_id_idx.find(2);
    if (it != by_id_idx.end()) { std::println("id 2: {} dept {}", it->name, it->dept); }

    // by dept (index 1)
    auto& by_dept_idx = emps.get<by_dept>();
    auto  range       = by_dept_idx.equal_range(10);
    std::print("dept 10: ");
    for (auto i = range.first; i != range.second; ++i) { std::print("{} ", i->name); }
    std::println("");

    // by name hash (index 2)
    auto& by_name_idx = emps.get<by_name>();
    auto  nit         = by_name_idx.find("Charlie");
    if (nit != by_name_idx.end()) { std::println("found Charlie, id={}", nit->id); }

    // iterate all
    std::print("all: ");
    for (const auto& e : emps) { std::print("{} ", e.name); }
    std::println("");

    return 0;
}
