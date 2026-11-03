#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std; 


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') { dp[i] = 0; continue; }

            if (s[i - 1] == '(') {
                // 情况 B1
                dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
            } else {
                // 情况 B2
                int p = i - dp[i - 1] - 1;          // 待匹配的 '(' 位置
                if (p >= 0 && s[p] == '(') {
                    dp[i] = dp[i - 1] + 2 + (p >= 1 ? dp[p - 1] : 0);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};