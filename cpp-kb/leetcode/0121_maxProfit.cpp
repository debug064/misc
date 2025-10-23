#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        //pair<size_t, size_t> found = {-1,-1};
        int found = 0;
        pair<size_t, size_t> cur = {-1,-1};
        for(size_t i = 0; i < prices.size(); ++i) {
            if(cur.first == -1) {
                cur.first = i;
                continue;
            }
            if(cur.first != -1 && cur.second != -1) {
                if(prices[cur.second] - prices[cur.first] > found){
                    found = prices[cur.second] - prices[cur.first];
                }
            }
            if(prices[cur.first] >= prices[i]) {
                cur.first = i;
                cur.second = -1;
                continue;
            }
            if(cur.second == -1) {
                cur.second = i;
                continue;
            }
            if(prices[cur.second] < prices[i]) {
                cur.second = i;
                continue;
            }
        }
        if(cur.first != -1 && cur.second != -1) {
                if(prices[cur.second] - prices[cur.first] > found){
                    found = prices[cur.second] - prices[cur.first];
                    
                }
            }
        return found;
    }

    int maxProfit(vector<int>& prices) {
        int curr = 0;
        int val = 0;
        for(size_t i = 1; i < prices.size(); ++i) {
            curr = max(0, curr + prices[i] - prices[i-1]);
            val = max(val, curr);
        }
        return val;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<int> nums;
    Solution sol;
    int res = 0;

    nums = {7,3,5,3,6,1,4, 5};
    res = sol.maxProfit(nums);
    assert(res == 4);

    nums = {7,1,5,3,6,4};
    res = sol.maxProfit(nums);
    assert(res == 5);

    nums = {1,2,4};
    res = sol.maxProfit(nums);
    assert(res == 3);

    nums = {1,2};
    res = sol.maxProfit(nums);
    assert(res == 1);

    

    nums = {7,6,4,3,1};
    res = sol.maxProfit(nums);
    assert(res == 0);
    cout << "end" << endl;
    return 0;
}