#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/trapping-rain-water/?envType=problem-list-v2&envId=rab78cw1


class Solution {
public:
    size_t find_first(size_t i, vector<int>& height) {
        size_t r = height.size();
        while(i < height.size()) {
            if(height[i] != 0)
                return i;
                ++i;
        }
        return r;
    }

    size_t find_next(size_t i, size_t prev, vector<int>& height) {
        size_t r = height.size();
        size_t max = i;
        while(i < height.size()) {
            if(height[i] > height[max])
                max = i;
            if(height[i] >= height[prev])
                return i;
            i += 1;
        }
        if(max > 0)
            return max;
        return r;
    }

    int trap(vector<int>& height) {
        size_t i = find_first(0, height);
        
        size_t j = find_next(i + 1, i, height);
        int sum = 0;
        while (j < height.size()) {
            int h = min(height[i], height[j]);
            for(++i; i < j; ++i) {
                sum += h - height[i];
            }
            i = j;
            j = find_next(i + 1, i, height);
        }

        return sum;
    }

    int trap_leet(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int maxl=height[l],maxr=height[r];
        int ans=0;

        while(l<r){
            if(maxl<maxr){
                l++;
                maxl=max(maxl,height[l]);
                ans+=maxl-height[l];
            }
            else{
                r--;
                maxr=max(maxr,height[r]);
                ans+=maxr-height[r];
            }
        }
        return ans;
    }
};

int main()
{
    cout << "begin"<< endl;
    vector<int> height ;
    Solution sol;
    {
        height = {5,4,1,2};
        assert(1 == sol.trap(height));

        height = {0,1,0,2,1,0,1,3,2,1,2,1};
        assert(6 == sol.trap(height));
    }
    cout << "end" << endl;
    return 0;
}
