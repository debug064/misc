#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/01-matrix/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:

    void visit(size_t i, size_t j, int base , vector<vector<int>>& mat, vector<int>& visited, std::deque<pair<size_t, size_t>>& todo) {
        if(mat[j][i] == base) {
            size_t rows = mat.size();
            size_t cols = mat[0].size();
            visited[j * cols + i] = 1;
            if(i > 0 && visited[j * cols + i-1] == 0 && mat[j][i-1] == 1) {
                todo.push_back({i-1, j});
                visited[j * cols + i-1] = 1;
            }
            if(i + 1 < cols && visited[j * cols + i+1] == 0 && mat[j][i+1] == 1) {
                todo.push_back({i+1, j});
                visited[j * cols + i+1] = 1;
            }
            if(j > 0 && visited[(j-1) * cols + i] == 0 && mat[j-1][i] ==  1) {
                todo.push_back({i, j-1});
                visited[(j-1) * cols + i] = 1;
            }
            if(j + 1 < rows && visited[(j+1) * cols + i] == 0 && mat[j+1][i] == 1) {
                todo.push_back({i, j+1});
                visited[(j+1) * cols + i] = 1;
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        std::deque<pair<size_t, size_t>> todo;
        size_t rows = mat.size();
        size_t cols = mat[0].size();
        vector<int> visited( rows*cols , 0);
        for(size_t j = 0; j < rows; ++j) {
            for(size_t i = 0; i < cols; ++i) {
                if(visited[j * cols + i] != 0)
                    continue;
                visit(i, j, 0, mat, visited, todo);
            }
        }

        int base = 1;
        std::deque<pair<size_t, size_t>> todo_next;
        while(!todo.empty()) {
                while(!todo.empty()) {
                auto [i, j] = todo.front();
                mat[j][i] = base;
                todo.pop_front();
                visit(i, j, base, mat, visited, todo_next);
            }
            swap(todo_next, todo);
            ++base;
        }
        return mat;
    }
};


int main()
{
    cout << "begin"<< endl;

    Solution sol;
    vector<vector<int>> mat;
    //mat = {{0,0,0},{0,1,0},{0,0,0}};
    mat = {{0,0,0, 1},{0,0,1, 1},{0,0,0, 1}};
    sol.updateMatrix(mat);

    cout << "end"<< endl;
    return 0;
}
