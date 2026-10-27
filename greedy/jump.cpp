#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int curEnd = 0, nextEnd = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            nextEnd = max(nextEnd, i + nums[i]);
            if (i == curEnd) {
                res++;
                curEnd = nextEnd;
            }
        }
        
        return res;
    }
};