#include "Problems.h"

using namespace std;

namespace MinCostClimbingStairs
{
  /*
  * https://leetcode.com/problems/min-cost-climbing-stairs/
  * YYou are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
  * You can either start from the step with index 0, or the step with index 1.
  * Return the minimum cost to reach the top of the floor.
  */

  class Solution {
  public:
    std::map<int, int> save;

    int minCostClimbingStairs(vector<int>& cost) {
      vector<int> sum(cost.size() );
      sum[0] = cost[0];
      sum[1] = cost[1];

      size_t i = 2;
      for (; i < cost.size(); ++i)
      {
        sum[i] = cost[i] + min(sum[i - 1], sum[i - 2]);
      }
      return min(sum[i - 1], sum[i - 2]);
    }

    int minCostClimbingStairs2(vector<int>& cost) {
      save.clear();
      int a = minCost(cost, 0);
      int b = minCost(cost, 1);
      return min(a, b);
    }

    int minCost(vector<int>& cost, size_t n) {
      if (n >= cost.size())
        return 0;
      if (auto it = save.find(n); it != save.end())
        return it->second;
      int a = minCost(cost, n + 1);
      int b = minCost(cost, n + 2);
      int val = cost[n] + min(a, b);
      save[n] = val;
      return val;
    }

    int climbStairs(int n) {
      if (n < 0)
        return 0;
      if (n == 0)
        return 1;
      if (auto it = save.find(n); it != save.end())
        return it->second;
      int ways = climbStairs(n - 1) + climbStairs(n - 2);
      save[n] = ways;
      return ways;
    }

    int climbStairs2(int n) {
      std::vector<int> stairs(n + 1);
      stairs[0] = 1;
      stairs[1] = 1;
      for (int i = 2; i <= n; i++) {
        stairs[i] = stairs[i - 1] + stairs[i - 2];
      }
      return stairs[n];
    }

  };

  void test()
  {
    Solution s;
    vector<int> nums;

    nums = { 10,15,20 };
    print(nums);
    cout << "The total cost is: " << s.minCostClimbingStairs(nums) << endl << endl;

    nums = { 1,100,1,1,1,100,1,1,100,1 };
    print(nums);
    cout << "The total cost is: " << s.minCostClimbingStairs(nums) << endl << endl;
  }
}