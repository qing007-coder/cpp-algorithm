#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
    vector<vector<char>> board;
    vector<vector<bool>> st;
    string word;
    string path;
    bool res;
    void dfs(int i, int j, int index) {
        if (path == word) {
            res = true;
            return ;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || st[i][j]) {
            return ;
        }

        if (board[i][j] == word[index]) {
            path.push_back(word[index]);
            st[i][j] = true;
            dfs(i + 1, j, index + 1);
            dfs(i - 1, j, index + 1);
            dfs(i, j + 1, index + 1);
            dfs(i, j - 1, index + 1);
            path.pop_back();
            st[i][j] = false;
        }
    }
public:
    bool exist(vector<vector<char>>& board_, string word_) {
        board = board_;
        word = word_;
        res = false;
        path.clear();
        int m = board.size(), n = board[0].size();
        st.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {  
                    dfs(i, j, 0);
                    if (res) return true;      
                }
            }
        }
        return false;
    }
};