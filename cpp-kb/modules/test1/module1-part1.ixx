module;



#include <iostream>



using namespace std;
export void MyFunc2();
export module module1:part1;

void MyFunc2()
{
  cout << "Module1:part1 Gloabal Func2." << endl;
}