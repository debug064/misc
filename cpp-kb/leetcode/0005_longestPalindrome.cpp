#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/?envType=problem-list-v2&envId=rab78cw1

class Solution
{
public:
    string PalindromicSubStrTest(string_view s, size_t l, size_t r)
    {
        string str;
        if (l >= s.size() || r >= s.size())
            return str;
        size_t l1{l}, r1{r};
        while (true)
        {
            --l1;
            ++r1;
            if (l1 >= s.size() || r1 >= s.size())
                return string{s.substr(l, r - l + 1)};

            if (s[l1] != s[r1])
                return string{s.substr(l, r - l + 1)};
            l = l1;
            r = r1;
        }
    }

    string longestPalindrome(string s)
    {
        string sub_str;
        if (s.empty())
            return sub_str;
        sub_str = s.substr(0, 1);
        for (size_t i = 0; i < s.size(); ++i)
        {
            size_t l = i - 1, r = i + 1;
            if (!(l < s.size()))
                l = i;
            if (!(r < s.size()))
                r = i;
            if (r == i)
                break;
            // looking center "bab" or "bb"
            if (s[i] == s[r]) // "bb" case
            {
                string str = PalindromicSubStrTest(s, i, r);
                // cout << str << endl;
                if (sub_str.size() < str.size())
                    sub_str = str;
            }
            if (i != l && s[r] == s[l]) // "bab" case
            {
                string str = PalindromicSubStrTest(s, l, r);
                // cout << str << endl;
                if (sub_str.size() < str.size())
                    sub_str = str;
            }
        }
        return sub_str;
    }
};

int main()
{
    Solution sol;
    auto res = sol.longestPalindrome("babad");
    assert("bab" == res || "aba" == res);

    res = sol.longestPalindrome("cbbd");
    assert("bb" == res);

    return 0;
}
