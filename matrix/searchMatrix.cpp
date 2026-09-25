#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        bool res = false;

        int y = 0, x = m - 1;
        while (y <= n - 1 && x >= 0) {
            if (matrix[y][x] == target) {
                res = true;
                break;
            } else if (matrix[y][x] > target) {
                x--;
            } else {
                y++;
            }
        }
        
        return res;
    }
};