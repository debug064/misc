#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/longest-palindrome/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> letters;
        int res = 0;
        for(auto c : s)
            if(auto it = letters.find(c); it != letters.end())
                it->second += 1;
            else
                letters[c] = 1;
        bool hasOne = false;
        for(const auto& p : letters)
            if(p.second % 2 == 1)
            {
                hasOne = true;
                res += p.second - 1;
            }
            else
                res += p.second;
        return hasOne ? res + 1: res;
    }
};

int main()
{
    Solution sol;
    auto res = sol.longestPalindrome("babad");
    assert(5 == res);

    res = sol.longestPalindrome("cbbd");
    assert(3 == res);

    res = sol.longestPalindrome("abccccdd");
    assert(7 == res);

    return 0;
}
