#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std; 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowHasZero = false, firstColumnHasZero = false;
        int width = (int)matrix[0].size(), height = (int)matrix.size();

        for (int i = 0; i < width; i++) {
            if (matrix[0][i] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        for (int i = 0; i < height; i++) {
            if (matrix[i][0] == 0) {
                firstColumnHasZero = true;
                break;
            }
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < height; i++) { 
            for (int j = 1; j < width; j++) { 
                if (matrix[i][0] == 0 || matrix[0][j] == 0) { 
                    matrix[i][j] = 0;
                }
            }
        }

        
        if (firstRowHasZero) {
            std::fill(matrix[0].begin(), matrix[0].end(), 0);
        }

        if (firstColumnHasZero) {
            for (int i = 0; i < height; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};