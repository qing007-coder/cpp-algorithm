#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])  {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int num = nums[i] + nums[left] + nums[right];
                if (num == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (num < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};
