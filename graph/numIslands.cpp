#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
    vector<vector<char>> grid_;

    void dfs(int i, int j) {
        int w = grid_[0].size();
        int h = grid_.size();

        if (i < 0 || i >= h || j < 0 || j >= w || grid_[i][j] != '1') {
            return ;
        }

        grid_[i][j] = '2';

        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);

        return ;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        grid_ = grid;
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid_[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
            
        }
        
        return ans;
    }
};