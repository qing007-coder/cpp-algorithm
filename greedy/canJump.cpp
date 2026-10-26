#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (maxReach < i) return false;
            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= n - 1) return true;
        }

        return false;
    }
};