#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std; 


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], dp = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            dp = max(nums[i], nums[i] + dp);
            res = max(res, dp);
        }
        
        return res;
    }
};