#include <format>
#include <iostream>
#include <vector>
using namespace std;

class A
{
    string a = "Hello";
    int b = {5};
    vector<uint16_t> vec;
public:
    A(const string a1, int b1):a(a1), b(b1) {}

    A() = delete;
    A(const A& other) = default;
    A& operator=(const A& other) = default;
    A(A&& other) = default;
    A& operator=(A&& other) = default;

    void print(string_view pre) {
        cout << format("{}: {} - {}", pre, a, b) <<endl;
    }
};

int main() 
{
    cout << "ctr_dst defaults" << endl;
    A a{"asd", 5};
    a.print("a"sv);
    cout << "=============" << endl;
    A b(a);
    a.print("a"sv);
    b.print("b"sv);
    cout << "=============" << endl;
    A c(move(a));
    a.print("a"sv);  // if empty, then default move
    b.print("b"sv);
    c.print("c"sv);
    cout << "=============" << endl;
    return 0;
}
