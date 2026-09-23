#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int index = nums.size() - k % nums.size();
        
        std::reverse(nums.begin(), nums.begin() + index);
        std::reverse(nums.begin() + index, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};