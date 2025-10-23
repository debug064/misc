#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/combination-sum-ii/

class Solution1 {
    set<multiset<int>> paths;
public:
    void trySum(vector<int>& candidates, size_t i, int target, multiset<int>& path) {
        if(target == 0) {
            paths.insert(path);
            return;
        }
        if(!(i < candidates.size()) || target < 0)
            return;

        auto itp = path.insert(candidates[i]);
        trySum(candidates, i+1, target - candidates[i], path);
        //path.pop_back();
        path.erase(itp);
        trySum(candidates, i+1, target, path);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        multiset<int> path;
        paths.clear();
        size_t i = 0;
        sort(candidates.begin(), candidates.end());

        trySum(candidates, i, target, path);

        vector<vector<int>> res;
        for(const auto& ms : paths) {
            vector<int> r;
            for(const auto& v : ms) {
                r.push_back(v);
            }
            res.push_back(r);
        }
        return res;
    }
};

class SolutionLeet {
public:

    // void helper(vector<vector<int>>&ans, vector<int>&arr, vector<int>&temp, int ind, int target){
    //     if(target==0){
    //         ans.push_back(temp);
    //         return;
    //     }

    //     for(int i=ind; i<arr.size(); i++){
    //         if(i>ind && arr[i] == arr[i-1]) continue;
    //         if(arr[i] > target) break;

    //         temp.push_back(arr[i]);
    //         helper(ans, arr, temp, ind+1, target-arr[i]);
    //         temp.pop_back();
    //     }
    // }

    // vector<vector<int>> combinationSum2(vector<int>&candidates, int target) {
    //     sort(candidates.begin(), candidates.end());
    //     vector<vector<int>> ans;
    //     vector<int> temp;
    //     helper(ans, candidates, temp, 0, target);
    //     return ans;
    // }

    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector < vector < int >> ans;
        vector < int > ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

class Solution {
    vector<vector<int>> paths;
public:
    void trySum(vector<int>& candidates, size_t i, int target, vector<int>& path) {
        if(target == 0) {
            paths.push_back(path);
            return;
        }
        if(!(i < candidates.size()) || target < 0)
            return;
        path.push_back(candidates[i]);
        trySum(candidates, i+1, target - candidates[i], path);
        path.pop_back();
        // skip same number in order to avoid dups
        while(i +1 < candidates.size() && candidates[i] == candidates[i+1])
            i += 1;
        trySum(candidates, i+1, target, path);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        paths.clear();
        sort(candidates.begin(), candidates.end());
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

    nums = {10,1,2,7,6,1,5};
    auto res = sol.combinationSum2(nums, 8);
    //assert(1 == res);

    nums = {2,2,2};
    res = sol.combinationSum2(nums, 2);

    nums = {2,3,5};
    res = sol.combinationSum2(nums, 8);
    //assert(3 == res);
    
    nums = {2};
    res = sol.combinationSum2(nums, 1);

    cout << "end" << endl;
    return 0;
}