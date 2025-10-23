module;


#include <iostream>

export module module1;
export import :part1;

using namespace std;
export void MyFunc();


void MyFunc()
{
  cout << "Module1 Gloabal Func." << endl;
}