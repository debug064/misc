#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/combination-sum/?envType=problem-list-v2&envId=rab78cw1

class Solution {
    vector<vector<int>> paths;
public:
    void trySum(vector<int>& candidates, size_t i, int target, vector<int>& path) {
        
        if(!(i < candidates.size()) || target < 0 )
            return;
        
        if(target == 0) {
            paths.push_back(path);
            return;
        }
        
        trySum(candidates, i + 1, target, path);
        path.push_back(candidates[i]);
        trySum(candidates, i, target - candidates[i], path);
        path.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        paths.clear();
        size_t i = 0;
        trySum(candidates, i, target, path);
        return paths;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<int> nums;
    Solution sol;

    nums = {2,3,6,7};
    auto res = sol.combinationSum(nums, 7);
    //assert(1 == res);

    nums = {2,3,5};
    res = sol.combinationSum(nums, 8);
    //assert(3 == res);
    
    nums = {2};
    res = sol.combinationSum(nums, 1);

    cout << "end" << endl;
    return 0;
}