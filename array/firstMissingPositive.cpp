#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res = 0, n = (int)nums.size();
    
        for (int i = 0; i < (int)nums.size(); i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                res = i + 1;
                break;
            }
        }
        
        if (res == 0) {
            res = n + 1;
        }
        
        return res;
    }
};