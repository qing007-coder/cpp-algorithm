#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
    vector<string> res;
    string path;
    int n;

    void dfs(int left, int right) {
        if (left == n && right == n) {
            res.push_back(path);
            return ;
        }

        if (left < n) {
            path.push_back('(');
            dfs(left + 1, right);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            dfs(left, right + 1);
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n_) {
        n = n_;
        dfs(0, 0);

        return res;
    }
};