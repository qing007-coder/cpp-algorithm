#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int i = 0;
        while(i <= high) {
            if (nums[i] == 0) {
                swap(nums[i], nums[low]);
                i++;
                low++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[high]);
                high--;
            } else {
                i++;
            }
        }
    }
};