#include <iostream>

using namespace std;

int main()
{
    cout << "raw strings";
    auto filename {R"(C:\Users\Marius\Documents\)"s};
    auto pattern{R"((\w+)=(\d+)$)"s};
    auto sqlselect{
        R"(SELECT *
  FROM Books
        WHERE Publisher='Packtpub'
  ORDER BY PubDate DESC)"s};

    cout << typeid(pattern).name() << endl;

    cout << sqlselect << endl;
    return 0;
}