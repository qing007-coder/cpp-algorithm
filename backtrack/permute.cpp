#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;

    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(path);
            return ;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                path.push_back(nums[i]);
                st[i] = true;
                dfs(nums, index + 1);
                path.pop_back();
                st[i] = false;
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        st.assign(nums.size(), false);

        int index = 0;

        dfs(nums, index);

        return res;
    }
};