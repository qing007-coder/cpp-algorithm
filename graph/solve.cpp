#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
private:
    vector<vector<char>> board;
    int m;
    int n;
    void dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '#';

        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    }
public:
    void solve(vector<vector<char>>& board_) {
        board = board_;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i) {
            dfs(i, 0);
            dfs(i, n - 1);
        }

        for (int j = 0; j < n; ++j) {
            dfs(0, j);
            dfs(m - 1, j);
        }
        

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }

        board_ = board;
    }
};