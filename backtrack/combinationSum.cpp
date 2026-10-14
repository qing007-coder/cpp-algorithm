#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
    vector<int> candidates;
    int target;
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int prev, int start) {
        if (prev == target) {
            res.push_back(path);
            return ;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (prev + candidates[i] > target) {
                break;
            }

            path.push_back(candidates[i]);

            dfs(prev + candidates[i], i);

            path.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates_, int target_) {
        sort(candidates_.begin(), candidates_.end());

        candidates = candidates_;
        target = target_;
        dfs(0, 0);

        return res;
    }
};