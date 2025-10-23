#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/rotting-oranges/description/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = 0;
        queue<pair<size_t, size_t>> rotten;
        for(size_t j = 0; j < grid.size(); ++j)
            for(size_t i = 0; i < grid[j].size(); ++i)
            {
                if(grid[j][i] == 2)
                    rotten.push({j, i});
            }
        
        queue<pair<size_t, size_t>> rott;
        while(!rotten.empty())
        {
            auto [j, i] = rotten.front();
            rotten.pop();
            // right
            if( i + 1 < grid[j].size() && grid[j][i+1] == 1)
                rott.push({j, i+1});//grid[j][i+1] = 2;
            // left
            if( i > 0 && grid[j][i-1] == 1)
                rott.push({j, i-1});//grid[j][i-1] = 2;
            // up
            if( j > 0 && grid[j-1][i] == 1)
                rott.push({j-1, i});//grid[j-1][i] = 2;
            // down
            if( j + 1 < grid.size() && grid[j+1][i] == 1)
                rott.push({j+1, i});//grid[j+1][i] = 2;
            if(rotten.empty())
            {
                if(rott.empty())
                    break;
                else
                {
                    while(!rott.empty())
                    {
                        auto pos = rott.front();
                        grid[pos.first][pos.second] = 2;
                        rott.pop();
                        rotten.push(pos);
                    }
                    ++m;
                }
            }
        }
        for(size_t j = 0; j < grid.size(); ++j)
            for(size_t i = 0; i < grid[j].size(); ++i)
                if(grid[j][i] == 1)
                    return -1;
        return m;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<vector<int>> grid;
    Solution sol;
    {
        grid = {{2,1,1},{1,1,0},{0,1,1}};
        assert(4 == sol.orangesRotting(grid));
    }

    cout << "end" << endl;
    return 0;
}