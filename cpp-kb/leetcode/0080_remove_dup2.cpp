#include "Problems.h"
#include <assert.h>

using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution {
public:
    const int APPEARED = 2;
    int removeDuplicatesV(vector<int>& nums) 
    {
        if(nums.empty()) 
            return 0;
        size_t i = 0, j = 1, n = 1, size = nums.size();
        while(j < size)
        {
            if(n < APPEARED && nums[i] == nums[j])
            {
                ++n;
                ++i; 
                if(i != j)
                    nums[i] = nums[j];
                ++j;
            }
            if(j < size && n == APPEARED && nums[i] == nums[j])
            {
                ++j;
            }

            if(j < size && nums[i] != nums[j])
            {
                n = 1;
                ++i;
                if(i != j)
                    nums[i] = nums[j];
            }
            ++j;
            
        }
        return ++i;
    }

    int removeDuplicates(vector<int> &nums)
    {
        int i = APPEARED;
        if(nums.size() < APPEARED) 
            return nums.size();
        for (size_t j = APPEARED; j < nums.size(); ++j)
        {

            if (nums[i - APPEARED] != nums[j])
            {
                nums[i] = nums[j];
                i += 1;
            }
        }

        return i;
    }
};

int main()
{
    Solution s;
  {
    vector<int> nums = {1,1,1,2,2,3}; // Input array
    vector<int> expectedNums = {1,1,2,2,3}; // The expected answer with correct length

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
    vector<int> nums = {0,0,1,1,1,1,2,3,3}; // Input array
    vector<int> expectedNums = {0,0,1,1,2,3,3}; // The expected answer with correct length

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
    vector<int> nums = {0,1,2,3,4,5,6,7, 8, 9 , 10}; // Input array
    vector<int> expectedNums = {0,1,2,3,4,5,6,7, 8, 9 , 10}; // The expected answer with correct length

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