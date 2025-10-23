#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/contains-duplicate/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nn;
        for(auto n : nums) {
            //auto it = nn.insert(n);
            if(nn.insert(n).second == false)
                return true;
        }
        return false;
    }
};


int main()
{
    cout << "begin" << endl;
    Solution sol;
    vector<int> nums;
    {

        nums = {1,2,3,1};
        assert(true == sol.containsDuplicate(nums));
        nums = {1,2,3,4};
        assert(false == sol.containsDuplicate(nums));
    }
    cout << "end" << endl;
    return 0;
}
