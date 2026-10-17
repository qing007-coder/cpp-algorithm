#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
    string s;
    vector<string> path;
    vector<vector<string>> res;

    void dfs(int start) {
        if (start == s.size()) {
            res.push_back(path);
            return ;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                dfs(end + 1);
                path.pop_back();
            }
        }
        
    }

    bool isPalindrome(int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s_) {
        s = s_;

        dfs(0);

        return res;
    }
};