#include <iostream>
#include <vector>
#include <compare>
#include <span>

using namespace std;

template<typename T>
void print(const span<T> sp) {
    for(auto v : sp)
        cout << v << " ";
    cout << endl;
}

struct Basics {
  int i;
  char c;
  float f;
  double d;
  auto operator <=> (const Basics&) const = default;
};

struct Arrays {
  int ai[1];
   char ac[2];
//   float af[3];
//   double ad[2][2];
  auto operator<=>(const Arrays&) const = default;
};

struct Bases : Basics, Arrays {
  auto operator<=>(const Bases&) const = default;
  std::string val;
};

// Driver Code
int main()
{
    int a = 91, b = 110;
    auto ans1 = a <=> b;
  
    if (ans1 < 0) {
        cout << "a < b\n";
    }
    else if (ans1 == 0) {
        cout << "a == b\n";
    }
    else if (ans1 > 0) {
        cout << "a > b\n";
    }
  
    vector<int> v1{ 3, 6, 9 };
    vector<int> v2{ 3, 6, 9 };
    auto ans2 = v1 <=> v2;
  
    if (ans2 < 0) {
        cout << "v1 < v2\n";
    }
    else if (ans2 == 0) {
  
        cout << "v1 == v2\n";
    }
    else if (ans2 > 0) {
  
        cout << "v1 > v2\n";
    }
  
    cout << endl;

    {
        Basics a = {0, 'c', 1.f, 1.};
        Basics b = {0, 'c', 1.f, 1.};
        if (a == b)
            cout << "a == b\n";
    }
    void test_complex();
    test_complex();

    print(span(v1));
}

void test_complex()
{
    // https://devblogs.microsoft.com/cppblog/simplify-your-code-with-rocket-science-c20s-spaceship-operator/
    constexpr Bases a = { { 0, 'c', 1.f, 1. },
                        { { 1 } , { 'a', 'b' }/*, { 1.f, 2.f, 3.f }, { { 1., 2. }, { 3., 4. } }*/ },
                        {"val"} };
  constexpr Bases b = { { 0, 'c', 1.f, 1. },
                        { { 1 }, { 'a', 'b' }/*, { 1.f, 2.f, 3.f }, { { 1., 2. }, { 3., 4. } } */},
                        {"val"}};
  static_assert(a == b);
  static_assert(!(a != b));
  static_assert(!(a < b));
  static_assert(a <= b);
  static_assert(!(a > b));
  static_assert(a >= b);
}

