#include <vector>
#include <unordered_set>
#include <iostream>
#include <queue>
using namespace std; 


class Solution {
private:
    vector<vector<int>> grid_;
    int m;
    int n;
    int dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid_[i][j] != 1) {
            return 0;
        }

        grid_[i][j] = 2;
        return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        grid_ = grid;
        int res = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid_[i][j] == 1) {
                    res = max(res, dfs(i, j));
                }
            }
        }

        return res;
    }
};