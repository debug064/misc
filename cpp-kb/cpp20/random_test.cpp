#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    auto mtgen = mt19937{rd()};
    auto ud = uniform_int_distribution<int>(1,6);

    for(auto i = 0; i < 25; ++i) 
    {
        cout << ud(mtgen) << " ";
    }
    cout << endl;

    //repeat every start
    auto mtgen1  = mt19937();
    for(auto i = 0; i < 25; ++i) 
    {
        cout << ud(mtgen1) << " ";
    }
    cout << endl;
}