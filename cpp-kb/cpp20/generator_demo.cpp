#include <chrono>
#include <experimental/generator>
#include <iostream>

using namespace std;

experimental::generator<int> GetSequenceGenerator(int startValue, size_t numOfValues)
{
    for(int i {startValue}; i < startValue + numOfValues; ++i)
    {
        time_t t {chrono::system_clock::to_time_t(chrono::system_clock::now())};
        cout << std::ctime(&t);
        co_yield i;
    }
}

int main()
{
    auto gen {GetSequenceGenerator(10, 5)};
    for(const auto& val : gen)
    {
        cout << val << " Press enter for next val\n";
        cin.ignore();
    }
}