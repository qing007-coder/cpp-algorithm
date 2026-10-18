#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            int mid_num = matrix[mid / n][mid % n];

            if (mid_num == target) {
                return true;
            }

            if (mid_num > target) {
                right = mid - 1;
            }

            if (mid_num < target) {
                left = mid + 1;
            }
        }

        return false;
        
    }
};