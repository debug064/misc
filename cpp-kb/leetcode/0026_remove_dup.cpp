#include "Problems.h"
#include <assert.h>

using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.empty()) 
            return 0;
        size_t i = 0, j = 1;
        while(j < nums.size())
        {
            if(nums[i] != nums[j])
            {
                ++i;
                if(i != j)
                    nums[i] = nums[j];
            }
            ++j;
        }
        return ++i;
    }
};

int main()
{
    Solution s;
  {
    vector<int> nums = {1, 1, 2}; // Input array
    vector<int> expectedNums = {1, 2}; // The expected answer with correct length

    print(nums);
    int k = s.removeDuplicates(nums); // Calls your implementation
    print(nums);
    assert(k == expectedNums.size());
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
        assert( nums[i] == expectedNums[i]);
    }
    cout << endl;
  }
  {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4}; // Input array
    vector<int> expectedNums = {0,1,2,3,4}; // The expected answer with correct length

    print(nums);
    int k = s.removeDuplicates(nums); // Calls your implementation
    print(nums);
    assert(k == expectedNums.size());
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
        assert( nums[i] == expectedNums[i]);
    }
    cout << endl;
  }
}