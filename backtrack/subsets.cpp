#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& nums, int start) {
        res.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i - 1] == nums[i]) {
                continue;
            }

            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 0;
        dfs(nums, start);

        return res;
    }
};