#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        vector<int> curRow = {1};
        for (int i = 1; i < numRows; i++) {

            vector<int> temp;
            temp.push_back(0);
            temp.insert(temp.end(), curRow.begin(), curRow.end());
            temp.push_back(0);

            for (int i = 0; i < temp.size() - 1; i++) {
                temp[i] = temp[i] + temp[i + 1];
            }
            temp.pop_back();
            curRow = temp;

            res.push_back(curRow);
        }
        
        return res;
    }
};