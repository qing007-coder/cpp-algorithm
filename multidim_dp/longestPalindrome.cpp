#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;           // 空串或单字符直接返回

        int start = 0;                 // 最长回文的起点
        int maxLen = 1;                // 最长回文的长度（至少 1）

        // 对每个位置 i，分别以「单字符」和「两字符之间」为中心扩展
        for (int i = 0; i < n; i++) {
            // 情况 1：奇数长度，中心是 i 自己
            int len1 = expand(s, i, i);
            // 情况 2：偶数长度，中心在 i 和 i+1 之间
            int len2 = expand(s, i, i + 1);

            int len = max(len1, len2); // 取两种中心里更长的

            if (len > maxLen) {        // 刷新记录
                maxLen = len;
                // 由「中心 i」和「长度 len」反推起点
                // 奇数: 起点 = i - len/2
                // 偶数: 起点 = i - (len-1)/2
                // 统一写成下面这个式子
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

private:
    // 从中心 (L, R) 向两边扩，返回回文长度
    int expand(const string& s, int L, int R) {
        while (L >= 0 && R < (int)s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};