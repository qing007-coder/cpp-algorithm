#include <vector>
#include <unordered_set>
#include <iostream>
#include <queue>
using namespace std; 


class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;

        int m = maze.size();
        int n = maze[0].size(); 

        q.push({entrance[0], entrance[1]});
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            steps++;
            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(auto [dx, dy]: dirs) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny] == '+') continue;

                    if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1) return steps;

                    q.push({nx, ny});
                    maze[nx][ny] = '+';
                }
            }
        }

        return -1;
    }
};