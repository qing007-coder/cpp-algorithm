#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxDP = nums[0], minDP = nums[0], n = nums.size();
        int res = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            int oldMax = maxDP, oldMin = minDP;  
            maxDP = max({x, oldMax * x, oldMin * x});
            minDP = min({x, oldMax * x, oldMin * x});

            res = max(res, maxDP);
        }

        return res;
    }
};