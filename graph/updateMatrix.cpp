#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dirs[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};