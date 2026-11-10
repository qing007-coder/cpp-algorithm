#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // 1. 找快慢指针相遇点
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // 2. 一个指针回到起点，再同速前进，相遇点就是环入口
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};