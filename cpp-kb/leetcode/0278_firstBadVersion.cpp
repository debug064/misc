#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/first-bad-version/?envType=problem-list-v2&envId=rab78cw1


int bad = 0;

bool isBadVersion(int version)
{
    return bad <= version;
}

class Solution {
public:
    // 1 <= bad <= n <= 231 - 1
    int firstBadVersion2(int n) {
        int f = 0, i = 0, step = 0;
        int count = n;
        while(count > 0)
        {
            i = f;
            step = count / 2;
            i += step;
            bool res = isBadVersion(i + 1);
            if(res == false)
            {
                f = i + 1;
                count -= step + 1;
            }
            else
                count = step;
        }
        return f + 1;
    }

    int firstBadVersion3(int n) {
        int f = 0, i = 0, step = 0;
        int size = n;
        while(0 < size)
        {
            i = f;
            step = size / 2;
            i += step;
            if(false == isBadVersion(i + 1))    // less function
            {
                f = ++i;
                size -= step + 1;
            }
            else
                size = step;
        }
        return f+1;
    }

    int firstBadVersion(int n) {
        int f = 0, i = 0, step = 0;
        int size = n;
        while(0 < size)
        {
            i = f;
            step = size / 2;
            i += step;
            //if(0 > (int)isBadVersion(i + 1) ) //lower bound
            if(0 >= (int)isBadVersion(i + 1)) //upper bound
            {
                f = ++i;
                size -= step + 1;
            }
            else
                size = step;
        }
        return f+1;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<string> tokens;
    Solution sol;
    bad = 4;
    assert(4 == sol.firstBadVersion(6));
    bad = 1;
    assert(1 == sol.firstBadVersion(2));
    
    bad = 4;
    assert(4 == sol.firstBadVersion(5));
    bad = 1;
    assert(1 == sol.firstBadVersion(1));
    
    
    cout << "end" << endl;
    return 0;
}