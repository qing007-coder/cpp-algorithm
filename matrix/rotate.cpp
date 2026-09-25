#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 转置
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);

        // 每一行左右翻转
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n / 2; ++j)
                swap(matrix[i][j], matrix[i][n - 1 - j]);
    }
};