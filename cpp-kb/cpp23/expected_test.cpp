#include <expected>
#include <iostream>
#include <random>

using namespace std;

expected<string, int> findRec()
{
    random_device rd;
    auto mtgen = mt19937{rd()};
    auto ud = uniform_int_distribution<int>(1,6);
    if(ud(mtgen) % 2 == 0)
      return unexpected(-1);
    return "Found";
}

// Driver Code
int main()
{
    for(auto i = 0; i < 20; ++i) 
    {
        auto res = findRec();
        if(res)
            cout << "found " << res.value() << endl;
        else
            cout << "Error " << res.error() << endl;
    }
}