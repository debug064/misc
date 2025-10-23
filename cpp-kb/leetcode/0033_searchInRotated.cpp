#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        if(nums.size() == 1)
            return nums.front() == target ? 0 : -1;
        // 1. Find index of 0 {4,5,6,7,0,1,2};
        size_t left = 0, right = nums.size() - 1;
        size_t count = nums.size(), step = 0;
        while(count > 1) {
            step = count / 2;
            if(nums[left] < nums[right]) {
                // return left;  //  pivot index of rotated at an unknown 
                right = nums.size();
                break; 
            }
            if(nums[left + step] >= nums[left])
                left += step;
            else if(nums[left + step] < nums[right])
                right = left + step;
            count = right - left;
        }
        //return right;
        if(target >= nums.front()) {
            auto last = next(nums.begin(), right );
            auto it = lower_bound(nums.begin(), last, target);
            if(it == last || *it != target)
                return -1;
            else 
                return it - nums.begin();
        }
        else if(target <= nums.back()) {
            auto it = lower_bound(next(nums.begin(), right), nums.end(), target);
            if(it == nums.end() || *it != target)
                return -1;
            else 
                return right + (it - next(nums.begin(), right));
        }
        return -1;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<int> nums;
    Solution sol;

    nums = {1};
    auto res = sol.search(nums, 1);
    assert(0 == res);

    nums = {15,16,19,20,25,1,3,4,5,7,10,14};
    res = sol.search(nums, 25);
    assert(4 == res);

    nums = {3, 1};
    res = sol.search(nums, 3);
    assert(0 == res);

    nums = {1, 3};
    res = sol.search(nums, 0);
    assert(-1 == res);

    nums = {1, 3};
    res = sol.search(nums, 3);
    assert(1 == res);

    //assert(0 == sol.search(nums, 0));
    assert(-1 == sol.search(nums, 0));
    nums = {4,5,6,7,0,1,2};
    res = sol.search(nums, 0);
    assert(4 == res);
    nums = {4,5,6,7,8,0,1,2};
    assert(5 == sol.search(nums, 0));
    nums = {0,1,2,4,5,6,7,8};
    assert(0 == sol.search(nums, 0));

    // nums = { 1,19,2,3,5};
    // assert(false == sol.canPartition(nums));
    
    cout << "end" << endl;
    return 0;
}