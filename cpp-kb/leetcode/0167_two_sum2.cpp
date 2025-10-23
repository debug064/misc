#include "Problems.h"

using namespace std;


namespace TwoSum2
{
  /*
  Given a 1 - indexed array of integers numbers that is already sorted in non - decreasing order, find two numbers such that they add up to a specific target number.Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

    Return the indices of the two numbers, index1and index2, added by one as an integer array[index1, index2] of length 2.

    The tests are generated such that there is exactly one solution.You may not use the same element twice.

    Your solution must use only constant extra space.
    */

  class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      if (nums.empty())
        return {};
      int i = 0, j = (int)nums.size()-1;

      while (i < j)
      {
        if (nums[i] + nums[j] < target)
          ++i;
        else if (nums[i] + nums[j] > target)
          --j;
        else
          return { i, j };
      }
      return {};
    }
  };

  void test()
  {
    vector<int> nums;
    int target = 0;
    Solution s;

    nums = { 2,7,11,15 };
    target = 9;
    cout << "target = " << target << "   ";
    print(nums);
    print(s.twoSum(nums, target));

    nums = { 2,3,4 };
    target = 6;
    cout << "target = " << target << "   ";
    print(nums);
    print(s.twoSum(nums, target));

    nums = { -1, 0 };
    target = -1;
    cout << "target = " << target << "   ";
    print(nums);
    print(s.twoSum(nums, target));
  }
}