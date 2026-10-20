#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (right + left) / 2;
            if (nums[mid] == nums[right]) {
                right--;
            }

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }

            if (nums[mid] < nums[right]) {
                right = mid;
            }
        }

        return nums[left];
    }
};