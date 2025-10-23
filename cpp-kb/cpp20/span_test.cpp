
#include <iostream>
#include <vector>
#include <compare>
#include <span>

//using namespace std;

// void println(const auto& seq)
// {
//     for (const auto& elem : seq)
//         std::cout << elem << ' ';
//     std::cout << '\n';
// }

// void print_span(std::span<const int> s)
// {
//     for (int n : s)
//         std::cout << n << ' ';
//     std::cout << '\n';
// }

int main() 
{
    std::vector <std::pair<int, int>> edge;

    edge.push_back({5, 6});
    std::cout << "Hello\n";
    constexpr int a[]{0, 1, 2, 3, 4, 5, 6, 7, 8};

    std::span<const int> s1 = a;
    //print_span(s1);
    for (int n : s1)
         std::cout << n << ' ';
     std::cout << '\n';
}

//clang++ cpp20/span_test.cpp -std=c++20 -o cpp20/test && ./cpp20/test