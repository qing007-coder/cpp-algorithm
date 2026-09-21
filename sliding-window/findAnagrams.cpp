#include <iostream>
#include <vector>
#include <array>

using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 统计 p 的每种字母的出现次数
        array<int, 26> cnt_p{}; 
        for (char c : p) {
            cnt_p[c - 'a']++;
        }

        vector<int> ans;
        array<int, 26> cnt_s{}; // 统计 s 的长为 p.size() 的子串 t 的每种字母的出现次数
        for (int right = 0; right < s.size(); right++) {
            cnt_s[s[right] - 'a']++; // 右端点字母进入窗口
            int left = right - p.size() + 1;
            if (left < 0) { // 窗口长度不足 p.size()
                continue;
            }
            if (cnt_s == cnt_p) { // t 和 p 的每种字母的出现次数都相同
                ans.push_back(left); // t 左端点下标加入答案
            }
            cnt_s[s[left] - 'a']--; // 左端点字母离开窗口
        }
        return ans;
    }
};
