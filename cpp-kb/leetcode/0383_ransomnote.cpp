#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/ransom-note/description/?envType=problem-list-v2&envId=rab78cw1

class Solution {
    
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<string::value_type, int> noteLetters;
        for(auto c : ransomNote)
        {
            auto it = noteLetters.find(c);
            if(it == noteLetters.end())
            {
                noteLetters[c] = 1;
            }
            else
            it->second += 1;
        }

        for(auto c : magazine)
        {
            auto it = noteLetters.find(c);
            if(it != noteLetters.end())
            {
                it->second -= 1;
                if(it->second <= 0)
                {
                    noteLetters.erase(it);
                    if(noteLetters.empty())
                        break;
                }
            }
        }
        return noteLetters.empty();
    }
};


int main()
{
    Solution sol;
    //sol.calculate("  ");
    assert(false == sol.canConstruct("a", "b"));
    assert(false == sol.canConstruct("aa", "ab"));
    assert(true == sol.canConstruct("a1", "aba1"));
    return 0;
}
