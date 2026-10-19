#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) return mid;

            // 左边局部有序
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // target在左边
                } else {
                    left = mid + 1; // target没在左边
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};