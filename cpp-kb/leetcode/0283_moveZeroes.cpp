#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/move-zeroes/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t z = 0;
        for(size_t i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                z+=1;
                continue;
            }
            if(z > 0)
                swap(nums[i - z ], nums[i]);
        }
    }
};

int main()
{
    cout << "begin"<< endl;
    vector<int> nums;
    Solution sol;

    nums = {4,2,4,0,0,3,0,5,1,0};
    sol.moveZeroes(nums);
    print(nums);

    nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    print(nums);
    //assert(nums == {1,3,12,0,0});
    cout << "end" << endl;
    return 0;
}