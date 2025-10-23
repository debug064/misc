#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Employee
{
    int age;
    std::string name; // Does not participate in comparisons
};

bool operator<(const Employee &lhs, const Employee &rhs)
{
    return lhs.age < rhs.age;
}

int main()
{
    // https://stackoverflow.com/a/64070091/1706731
    {
        std::vector<Employee> v =
            {
                {32, "Arthur3"},
                {108, "Zaphod"},
                {108, "Ford"},
                {32, "Arthur2"},
            };

        std::stable_sort(v.begin(), v.end());

        for (const Employee &e : v)
            std::cout << e.age << ", " << e.name << '\n';
    }
    {
        std::vector<Employee> v =
            {
                {32, "Arthur3"},
                {108, "Zaphod"},
                {108, "Ford"},
                {32, "Arthur2"},
            };

        std::sort(v.begin(), v.end());

        for (const Employee &e : v)
            std::cout << e.age << ", " << e.name << '\n';
    }
}