#include "Problems.h"

using namespace std;

//https://leetcode.com/problems/valid-palindrome/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    bool isPalindrome2(string s) {
        if(s.empty())
            return true;

        size_t i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(!isalnum(s[i]))
            {
                ++i;
                continue;
            }
            if(!isalnum(s[j]))
            {
                --j;
                continue;
            }
            if(toupper(s[i]) != toupper(s[j]))
                return false;
            ++i;
            --j;
        }
        return true;
    }

    bool isPalindrome(string s) {
        if(s.empty())
            return true;

        size_t i = 0, j = s.size() - 1;
        while(i < j)
        {
            while(i < j && !isalnum(s[i]))
                ++i;
            while( i < j && !isalnum(s[j]))
                --j;
            if(toupper(s[i]) != toupper(s[j]))
                return false;
            ++i;
            if(j > 0)
                --j;
        }
        return true;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<int> nums;
    Solution sol;
    bool res = 0;

    res = sol.isPalindrome("A.");
    assert(res == true);

    res = sol.isPalindrome("0P");
    assert(res == false);

    res = sol.isPalindrome("A man, a plan, a canal: Panama");
    assert(res == true);

    res = sol.isPalindrome(" ");
    assert(res == true);

    
    cout << "end" << endl;
    return 0;
}