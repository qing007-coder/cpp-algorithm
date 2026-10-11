#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0, ans = 0;
        int h = grid.size(), w = grid[0].size();

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++){
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // 四个方向：上 下 左 右
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty() && fresh != 0) {
            int size = q.size();
            for (int time = 0; time < size; time++) {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                    if (grid[ni][nj] != 1) continue;

                    grid[ni][nj] = 2;   
                    fresh--;           
                    q.push({ni, nj});
                }
            }
            ans += 1;
        }
        
        if (fresh == 0) {
            return ans;
        } else {
            return -1;
        }
    }
};