#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/majority-element/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0, count = 0;
        for(auto n : nums) {
            if(count == 0) {
                num = n;
                count += 1;
            }
            else {
                if(num == n)
                    count += 1;
                else
                    count -= 1;
            }
        }
        return num;
    }
};

int main()
{
    cout << "begin"<< endl;
    vector<int> nums;
    Solution sol;

    nums = {1};
    auto res = sol.majorityElement(nums);
    assert(1 == res);

    nums = {3,2,3};
    res = sol.majorityElement(nums);
    assert(3 == res);
    
    cout << "end" << endl;
    return 0;
}