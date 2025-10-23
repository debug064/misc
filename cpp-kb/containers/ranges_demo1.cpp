#include <vector>
#include <ranges>
#include <iostream>

#include <experimental/generator>

void test_ranges1()
{
    using namespace std;
    vector data{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    auto result{data | views::filter([](auto const &val)
                                     { return val % 2; }) |
                views::reverse | views::drop(1)};

    for (const auto &val : result)
        cout << val << " ";
    cout << endl;
}

int main()
{
    using namespace std;
    cout << "Hello CMake." << endl;
    test_ranges1();

    return 0;
}
