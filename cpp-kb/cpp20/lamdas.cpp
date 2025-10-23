#include <format>
#include <iostream>
#include <vector>
#include <random>

int main()
{
    std::vector<int> v = {5, 123, 54,12,55,13,5435,84}; 
    int count = 14;
    //auto l1 = [count]() mutable {std::cout << ++count <<std::endl;};
    auto l1 = [count]() {std::cout << ++count <<std::endl;};
    l1();
    std::cout << count <<std::endl;

}