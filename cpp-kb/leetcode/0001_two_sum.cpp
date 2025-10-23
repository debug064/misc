#include "Problems.h"

using namespace std;

namespace TwoSum
{
  /*
  * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  You can return the answer in any order.
  */

  class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> num_to_i;
      int val(0);
      for (size_t i = 0; i < nums.size(); ++i)
      {
        val = target - nums[i];
        auto it = num_to_i.find(val);
        if (it == num_to_i.end())
          num_to_i[nums[i]] = (int)i;
        else
          return { it->second, (int)i };
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

    nums = { 3,2,4 };
    target = 6;
    cout << "target = " << target << "   ";
    print(nums);
    print(s.twoSum(nums, target));

    nums = { 3, 3 };
    target = 6;
    cout << "target = " << target << "   ";
    print(nums);
    print(s.twoSum(nums, target));
  }
}

int main()
{
  TwoSum::test();
}