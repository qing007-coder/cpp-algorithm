#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left = 0, right = nums.size() - 1;

        while(true) {
            int p = partition(nums, left, right);
            if (p == target) return nums[p];
            else if (p > target) right = p - 1;
            else left = p + 1;
        }

        return 0;
    }

private:
    int partition(vector<int>& a, int l, int r) {
        int idx = l + rand() % (r - l + 1);  // 随机化，防最坏 O(n^2)
        swap(a[idx], a[r]);
        int pivot = a[r], i = l;
        for (int j = l; j < r; ++j)
            if (a[j] < pivot) swap(a[i++], a[j]);
        swap(a[i], a[r]);
        return i;
    }
};