#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/valid-parentheses/?envType=problem-list-v2&envId=rab78cw1


class Solution {
public:
    bool isValid(string s) {
        string open = "([{";
        string close = ")]}";
        stack<string::value_type> brackets;
        for(auto c : s)
        {
            if(auto pos = open.find(c); pos != open.npos)
                brackets.push(close[pos]);
            else if(!brackets.empty() && c == brackets.top())
                brackets.pop();
            else
                return false;
        }
        return brackets.empty();
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<vector<int>> grid;
    Solution sol;
    assert(true == sol.isValid("()[]{}"));
    assert(false == sol.isValid("(]"));
    assert(false == sol.isValid("]"));
    
    cout << "end" << endl;
    return 0;
}