#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        if (n == 1) {
            return 1;
        }

        int dir[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});

        grid[0][0] = 1;

        while(!q.empty()) {
            auto [x, y, dist] = q.front();
            q.pop();
            for(int i = 0; i < 8; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }

                if (grid[nx][ny] == 1) {
                    continue;
                }

                if (nx == n - 1 && ny == n - 1) {
                    return dist + 1;
                }

                q.push({nx, ny, dist + 1});
                grid[nx][ny] = 1;
            }
        }

        return -1;
    }
};