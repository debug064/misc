#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/permutations/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    vector<vector<int>> permute1(vector<int>& nums) {
        if(nums.empty())
            return {};

        vector<vector<int>> res;
        vector<vector<int>> res2;
        res.push_back({nums[0]});

        // num 0, res.size() = 1, res[j].size() 1
        // insert 1 before 0
        // insert 1 after 0
        // now res.size() = 2
        // next num 2
        // insert 2 before 1
        // insert 2 between 1 and 0
        // insert 2 after 0
        // next j
        // insert 2 before 0
        // insert 2 between 0 and 1
        // insert 2 after 1

        for(size_t i = 1; i < nums.size(); ++i)
        {
            for(size_t j = 0; j < res.size(); ++j)
                for(size_t k = 0; k <= res[j].size(); ++k)
                {
                    auto p = res[j];
                    p.insert(p.begin() + k, nums[i]);
                    res2.emplace_back(p);
                }
            res = res2;
            res2.clear();
        }

        return res;
    }

    vector<vector<int>> res;
    void permute(vector<int>& nums, size_t n) {
        if(nums.size() - n <= 1)
        {
            res.push_back(nums);
            return;
        }
            
        for(size_t i = n; i < nums.size(); ++i) {
            swap(nums[n], nums[i]);
            permute(nums, n + 1);
            swap(nums[n], nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return {};
        res.clear();
        permute(nums, 0);

        return res;
    }

};

int main()
{
    cout << "begin" << endl;
    Solution sol;
    vector<int> nums;
    vector<vector<int>> res;
    {
        nums = {1,2,3};
        print(nums);
        std::cout << "----" << std::endl;
        print2(sol.permute(nums));

        nums = {0,1};
        print(nums);
        std::cout << "----" << std::endl;
        print2(sol.permute(nums));

        
    }
    cout << "end" << endl;
    return 0;
}
