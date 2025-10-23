#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/binary-search/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    int search_1(vector<int>& nums, int target) {
        size_t count = nums.size(), step = 0;
        int f = 0, i = 0;
        while(count > 0) {
            i = f;
            step = count / 2;
            i += step;
            if(target > nums[i]) {
                count -= step + 1;
                f = i+1;
            }
            else
                count = step;
        }
        return (f < nums.size() && target == nums[f]) ? f : -1;
    }

    // from LC
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]< target){
                low=mid+1;
            }
            else if(nums[mid]==target) return mid;
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};

int main()
{
    cout << "begin"<< endl;
    vector<int> nums;
    Solution sol;
    nums = {5};
    assert(-1 == sol.search(nums, -5));
    nums = {-1};
    assert(-1 == sol.search(nums, 2));
    nums = {-1,0,5};
    assert(1 == sol.search(nums, 0));
    assert(2 == sol.search(nums, 5));
    
    nums = {-1,0,3,5,9,12};
    assert(4 == sol.search(nums, 9));
    assert(-1 == sol.search(nums, 4));
    nums = {-1,0,3,5,9,10,12};
    assert(-1 == sol.search(nums, 4));
    // bad = 1;
    // assert(1 == sol.firstBadVersion(2));
    
    // bad = 4;
    // assert(4 == sol.firstBadVersion(5));
    // bad = 1;
    // assert(1 == sol.firstBadVersion(1));
    
    
    cout << "end" << endl;
    return 0;
}