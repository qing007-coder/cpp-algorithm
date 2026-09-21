#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std; 


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;
        int ans = 0;
        int prefixSum = 0;
        for (int num : nums) {
            prefixSum += num;
            ans += prefixMap[prefixSum - k];
            prefixMap[prefixSum]++;
        }

        return ans;
    }
};