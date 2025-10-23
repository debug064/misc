#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      size_t len = 0, left = 0, right = 0;
      std::map<string::value_type, size_t> str;
      for (auto const &c : s)
      {
        auto it = str.find(c);
        if (it != str.end())
        {
          len = right - left;
          auto pos = *it; 
          for (size_t j = left; j <= pos.second; ++j)
            str.erase(s[j]);
          ++left;
        }
        str[c] = right;
        ++right;
      }
      if (len < str.size())
        len = str.size();
      return (int)len;
    }
};

int main()
{
    Solution sol;
    assert(3 == sol.lengthOfLongestSubstring("abcabcbb"));
    return 0;
}