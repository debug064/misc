#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    std::map<pair<size_t, int>, bool> cache;
    bool doit(vector<int>& nums, size_t i, int sum) {
        if(!(i < nums.size()) || sum <= 0)
            return sum == 0;
        if(auto it = cache.find({i, sum}); it != cache.end())
            return it->second;
        bool res =  doit(nums, i + 1, sum - nums[i]) || doit(nums, i + 1, sum);
        cache[{i, sum}] = res;
        return res;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums) sum += n;

        if(sum & 1)
            return false;

        cache.clear();
        return doit(nums, 0, sum / 2);
    }
};

int main()
{
    cout << "begin"<< endl;
    vector<int> nums;
    Solution sol;
    nums = {1,5,11,5};
    assert(true == sol.canPartition(nums));

    nums = { 1,19,2,3,5};
    assert(false == sol.canPartition(nums));
    
    cout << "end" << endl;
    return 0;
}