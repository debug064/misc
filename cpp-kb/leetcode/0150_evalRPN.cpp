#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(const auto& val : tokens)
        {
            if(val == "+")
            {
                if(nums.size() < 2)
                    return 0;
                int sum = nums.top();
                nums.pop();
                sum += nums.top();
                nums.pop();
                nums.push(sum);
            }
            else if(val == "-")
            {
                if(nums.size() < 2)
                    return 0;
                int sum = nums.top();
                nums.pop();
                sum = nums.top() - sum;
                nums.pop();
                nums.push(sum);
            }
            else if(val == "*")
            {
                if(nums.size() < 2)
                    return 0;
                int sum = nums.top();
                nums.pop();
                sum *= nums.top();
                nums.pop();
                nums.push(sum);
            }
            else if(val == "/")
            {
                if(nums.size() < 2)
                    return 0;
                int sum = nums.top();
                nums.pop();
                sum = nums.top() / sum;
                nums.pop();
                nums.push(sum);
            }
            else
                nums.push(stoi(val));
        }
        if(nums.empty())
            return 0;
        return nums.top();
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<string> tokens;
    Solution sol;
    tokens = {"2","1","+","3","*"};
    assert(9 == sol.evalRPN(tokens));
    tokens = {"4","13","5","/","+"};
    assert(6 == sol.evalRPN(tokens));
    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    assert(22 == sol.evalRPN(tokens));
    
    cout << "end" << endl;
    return 0;
}