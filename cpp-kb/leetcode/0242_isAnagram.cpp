#include "Problems.h"

using namespace std;

//https://leetcode.com/problems/valid-anagram/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> chars;
        for(auto c : s)
            chars[c] += 1;
        for(auto c : t) {
            auto it = chars.find(c);
            if(it == chars.end())
                return false;
            if(it->second == 0)
                return false;
            it->second -= 1;
        }
        return true;
    }

bool isAnagram2(string s, string t) {
        if(s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    
};

int main()
{
    cout << "begin"<< endl;
    Solution sol;
    assert(true == sol.isAnagram("anagram", "nagaram"));

    cout << "end"<< endl;
    return 0;
}
