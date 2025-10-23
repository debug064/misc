#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/flood-fill/?envType=problem-list-v2&envId=rab78cw1


class Solution {
public:
    void mark(deque<pair<int, int>>& todo, vector<vector<int>>& image, size_t row, size_t col, int oldc, int newc) {
        if(image[row][col] == oldc && image[row][col] != newc )
            {
                image[row][col] = newc;
                todo.push_back({row, col});
            }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(sr < 0 || sc < 0)
            return {};
        if(!(sr < image.size()) || !(sc < image[0].size()))
            return {};

        deque<pair<int, int>> todo;
        int c = image[sr][sc];
        image[sr][sc] = color;
        todo.push_back({sr, sc});
        while(!todo.empty()) {
            auto pos = todo.front();
            todo.pop_front();
            if (pos.first - 1 >= 0)
                mark(todo, image, pos.first - 1, pos.second, c, color);
            if (pos.first + 1 < image.size())
                mark(todo, image, pos.first + 1, pos.second, c, color);
            
            if (pos.second - 1 >= 0)
                mark(todo, image, pos.first, pos.second - 1, c, color);
            if (pos.second + 1 < image[0].size())
                mark(todo, image, pos.first, pos.second + 1, c, color);
        }
        return image;
    }

    void mark(deque<pair<int, int>>& todo, vector<vector<int>>& image, vector<vector<bool>>& visited, size_t row, size_t col, int oldc, int newc) {
        if(visited[row][col] == false && image[row][col] == oldc )
            {
                image[row][col] = newc;
                visited[row][col] = true;
                todo.push_back({row, col});
            }
    }

    vector<vector<int>> floodFill2(vector<vector<int>>& image, int sr, int sc, int color) {
        if(sr < 0 || sc < 0)
            return {};
        if(!(sr < image.size()) || !(sc < image[0].size()))
            return {};
        vector<vector<bool>> visited;
        visited.resize(image.size());
        for(auto & v : visited)
            v.resize(image[0].size());

        deque<pair<int, int>> todo;
        int c = image[sr][sc];
        image[sr][sc] = color;
        visited[sr][sc] = true;
        todo.push_back({sr, sc});
        while(!todo.empty()) {
            auto pos = todo.front();
            todo.pop_front();
            if (pos.first - 1 >= 0)
                mark(todo, image, visited, pos.first - 1, pos.second, c, color);
            if (pos.first + 1 < image.size())
                mark(todo, image, visited, pos.first + 1, pos.second, c, color);
            
            if (pos.second - 1 >= 0)
                mark(todo, image, visited, pos.first, pos.second - 1, c, color);
            if (pos.second + 1 < image[0].size())
                mark(todo, image, visited, pos.first, pos.second + 1, c, color);
        }
        return image;
    }

    vector<vector<int>> floodFill1(vector<vector<int>>& image, int sr, int sc, int color) {
        if(sr < 0 || sc < 0)
            return {};
        if(!(sr < image.size()) || !(sc < image[0].size()))
            return {};
        vector<vector<bool>> visited;
        visited.resize(image.size());
        for(auto & v : visited)
            v.resize(image[0].size());

        deque<pair<int, int>> todo;
        int c = image[sr][sc];
        image[sr][sc] = color;
        visited[sr][sc] = true;
        todo.push_back({sr, sc});
        while(!todo.empty()) {
            auto pos = todo.front();
            todo.pop_front();
            if (pos.first - 1 >= 0 && visited[pos.first - 1][pos.second] == false && image[pos.first - 1][pos.second] == c )
            {
                image[pos.first - 1][pos.second] = color;
                visited[pos.first - 1][pos.second] = true;
                todo.push_back({pos.first - 1, pos.second});
            }
            if (pos.first + 1 < image.size() && visited[pos.first + 1][pos.second] == false && image[pos.first + 1][pos.second] == c)
            {
                image[pos.first + 1][pos.second] = color;
                visited[pos.first + 1][pos.second] = true;
                todo.push_back({pos.first + 1, pos.second});
            }

            if (pos.second - 1 >= 0 && visited[pos.first][pos.second - 1] == false && image[pos.first][pos.second - 1] == c)
            {
                image[pos.first][pos.second - 1] = color;
                visited[pos.first][pos.second - 1] = true;
                todo.push_back({pos.first , pos.second - 1});
            }
            if (pos.second + 1 < image[0].size() && visited[pos.first ][pos.second+ 1] == false && image[pos.first ][pos.second+ 1] == c)
            {
                image[pos.first][pos.second+ 1] = color;
                visited[pos.first][pos.second+ 1] = true;
                todo.push_back({pos.first, pos.second+ 1});
            }
        }
        return image;
    }
};


int main()
{
    cout << "begin" << endl;
    Solution sol;
    vector<vector<int>> image;
    {
        image = {{0,0,0},{0,0,0}};
        print2(image);
        print2(sol.floodFill(image, 1, 0, 2));

        image = {{1,1,1},{1,1,0},{1,0,1}};
        print2(image);
        print2(sol.floodFill(image, 1, 1, 2));
        // assert("11010010011000000000" == sol.floodFill("01110001111100001101", "01100000011011110011"));
        // assert("110001" == sol.addBinary("101111", "10"));
        // assert("100" == sol.addBinary("11", "1"));
        // assert("10101" == sol.addBinary("1010", "1011"));
        // assert("111" == sol.addBinary("101", "10"));
    }
    cout << "end" << endl;
    return 0;
}
