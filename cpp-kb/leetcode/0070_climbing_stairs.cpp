#include "Problems.h"

using namespace std;

namespace ClimbingStairs
{
  /*
  * https://leetcode.com/problems/climbing-stairs/
  * You are climbing a staircase. It takes n steps to reach the top.
  * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
  */

  class Solution {
  public:
    std::map<int, int> save;

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
    cout << "2 steps = " << s.climbStairs(2) << " ways\n";
    cout << "3 steps = " << s.climbStairs(3) << "\n";
    cout << "4 steps = " << s.climbStairs(4) << "\n";
    cout << "5 steps = " << s.climbStairs(5) << "\n";
    cout << "6 steps = " << s.climbStairs(6) << "\n";
    cout << "10 steps = " << s.climbStairs(10) << "\n";
    cout << "20 steps = " << s.climbStairs(20) << "\n";
    cout << "30 steps = " << s.climbStairs(30) << "\n";
    cout << "40 steps = " << s.climbStairs(40) << "\n";

    cout << "2 steps = " << s.climbStairs2(2) << " ways\n";
    cout << "3 steps = " << s.climbStairs2(3) << "\n";
    cout << "4 steps = " << s.climbStairs2(4) << "\n";
    cout << "5 steps = " << s.climbStairs2(5) << "\n";
    cout << "6 steps = " << s.climbStairs2(6) << "\n";
    cout << "10 steps = " << s.climbStairs2(10) << "\n";
    cout << "20 steps = " << s.climbStairs2(20) << "\n";
    cout << "30 steps = " << s.climbStairs2(30) << "\n";
    cout << "40 steps = " << s.climbStairs2(40) << "\n";
  }
}

int main()
{
  ClimbingStairs::test();
}