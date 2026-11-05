#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        // dp[i][j]: s1 前 i 个字符 与 s2 前 j 个字符 的 LCS 长度
        // 多开一行一列，dp[0][*] 和 dp[*][0] 都是 0（空串）
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // 末尾相同，配一对
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 末尾不同，丢掉一边，取较大
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};