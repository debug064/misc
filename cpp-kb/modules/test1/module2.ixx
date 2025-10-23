module;


#include <iostream>

export module module2;

using namespace std;
export void MyFunc();

export auto m_plus(auto x, auto y) -> decltype(x + y) {
  return x + y;
}

void MyFunc()
{
  cout << "Module2 Gloabal Func." << endl;
}

export {
  std::string butter();
//  std::string jam();
}