#include <memory>

#include <iostream>
#include <random>

#include <windows.h>

using namespace std;


// Driver Code
int main()
{
    unique_ptr<int> val;
    unique_ptr<HANDLE, decltype(&CloseHandle)> val2(nullptr, CloseHandle);   //no default constructor exists
}