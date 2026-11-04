#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                    continue;                    
                }
                int lastX = INT_MAX, lastY = INT_MAX;
                if (i != 0) lastX = dp[i - 1][j];
                if (j != 0) lastY = dp[i][j - 1];

                dp[i][j] = grid[i][j] + min(lastX, lastY);  
            }
        }

        return dp[m - 1][n - 1];
    }
};