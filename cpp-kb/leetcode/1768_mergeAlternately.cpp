#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str(word1.size() + word2.size(), 0);
        size_t i = 0, j = 0;
        for(; i < word1.size() && i < word2.size(); ++i, ++j)
        {
            str[j] = word1[i];
            str[++j] = word2[i];
        }
        if(word1.size() > word2.size())
            for(; i < word1.size(); ++i, ++j)
                str[j] = word1[i];
        else
            for(; i < word2.size(); ++i, ++j)
                str[j] = word2[i];
        cout << str << endl;
        return str;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<vector<int>> grid;
    Solution sol;
    assert("apbqcr" == sol.mergeAlternately("abc", "pqr"));
    assert("apbqrs" == sol.mergeAlternately("ab", "pqrs"));
    assert("apbqcd" == sol.mergeAlternately("abcd", "pq"));
    cout << "end" << endl;
    return 0;
}