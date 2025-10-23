#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/maximum-subarray/description/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int max = INT_MIN;
        int sum = 0;
        for(size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            max = ::max(max , sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<int> nums ;
    Solution sol;
    {
        nums = {-2,-1};
        assert(-1 == sol.maxSubArray(nums));

        nums = {-2,1,-3,4,-1,2,1,-5,4};
        assert(6 == sol.maxSubArray(nums));

        nums = {5,4,-1,7,8};
        assert(23 == sol.maxSubArray(nums));
    }
    cout << "end" << endl;
    return 0;
}
