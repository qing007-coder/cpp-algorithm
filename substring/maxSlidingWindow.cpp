#include <vector>
#include <unordered_map>
#include <iostream>
#include <deque>
using namespace std; 


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // 存储索引
        vector<int> result;
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back(); // 移除窗口外的索引
            }

            dq.push_back(i); // 将当前索引加入双端队列
            int left = i - k + 1; // 窗口的左边界索引

            if (left > dq.front()) {
                dq.pop_front(); // 移除窗口外的索引
            }

            if (left >= 0) {
                result.push_back(nums[dq.front()]); // 当前窗口的最大值
            }
        }
        return result;
    }
};