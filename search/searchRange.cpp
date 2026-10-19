#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        int L = -1, R = -1;

        // 左边界
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                L = mid;
                right = mid - 1;
            }

            if (nums[mid] > target) {
                right = mid - 1;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        if (L == -1) {
            return {-1, -1};
        }


        left = 0, right = nums.size() - 1;

        // 右边界
        while(left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                R = mid;
                left = mid + 1;
            }

            if (nums[mid] > target) {
                right = mid - 1;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            }
        }


        return {L, R};
    }
};