// test1.cpp : Defines the entry point for the application.
//

#include "test1.h"

import module1;
import module2;

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	MyFunc();
	cout << m_plus(2, 5) << endl;
	cout << butter() << endl;
	//cout << MyFunc2() << endl;
	
	return 0;
}
