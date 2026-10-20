#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int leftSize = (total + 1) / 2;

        int low = 0, high = m; // 这个low和high是专门给nums1用的 nums2用leftSize算出来
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = leftSize - i;

            int aL = (i == 0) ? INT_MIN : nums1[i-1];
            int aR = (i == m) ? INT_MAX : nums1[i];
            int bL = (j == 0) ? INT_MIN : nums2[j-1];
            int bR = (j == n) ? INT_MAX : nums2[j];

            if (aL > bR)      high = i - 1;   // i 太大
            else if (bL > aR) low = i + 1;   // i 太小
            else {
                if (total % 2) return max(aL, bL);
                return (max(aL, bL) + min(aR, bR)) / 2.0;
            }
        }
        return 0;
    }
};