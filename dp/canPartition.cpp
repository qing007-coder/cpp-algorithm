#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std; 


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int n = nums.size();
        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : nums) {
            for(int j = target; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
            if (dp[target]) return true;
        }

        return dp[target];
    }
};