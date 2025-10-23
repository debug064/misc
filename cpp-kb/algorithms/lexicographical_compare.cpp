#include <algorithm>
#include <execution>
#include <chrono>
#include <functional>
#include <iostream>
#include <string_view>
#include <thread>
#include <vector>

void print(std::string_view text, std::vector<int> const &v = {})
{
    std::cout << text << ": ";
    for (const auto &e : v)
        std::cout << e << ' ';
    std::cout << '\n';
}

int main()
{
    print("lexicographical_compare");
    {
        std::vector<int> range1{1, 2, 3};
        std::vector<int> range2{1, 3};
        std::vector<int> range3{1, 3, 1};

        bool cmp1 = std::lexicographical_compare(range1.begin(), range1.end(),
                                                 range2.begin(), range2.end());
        std::cout << "cmp1: " << cmp1 << "\n";
        // same as
        bool cmp2 = range1 < range2;
        // cmp1 == cmp2 == true
        std::cout << "cmp2: " << cmp2 << "\n";

        bool cmp3 = std::lexicographical_compare(range2.begin(), range2.end(),
                                                 range3.begin(), range3.end());

        std::cout << "cmp3: " << cmp3 << "\n";
    }
    print("lexicographical_compare std::vector<std::string>");

    {
        std::vector<std::string> names1{"Zod", "Celeste"};
        std::vector<std::string> names2{"Adam", "Maria"};

        bool cmp2 = std::ranges::lexicographical_compare(names1, names2,
                                                         [](const std::string &left, const std::string &right)
                                                         {
                                                             return left.length() < right.length();
                                                         });
        // different than
        bool cmp3 = names1 < names2; // Zod > Adam

        std::cout << "cmp2: " << cmp2 << "\n";
        std::cout << "cmp3: " << cmp3 << "\n";
    }
    return 0;
}