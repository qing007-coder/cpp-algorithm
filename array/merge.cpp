#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std; 


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        for(vector<int> interval: intervals) {
            int leftInterval = interval[0], rightInterval = interval[1];
            if (!res.size() || (res.back()[1] < leftInterval)) { // [1, 2],  [3, 4]
                res.push_back(interval);
                continue;
            }

            vector<int> back = res.back();

            // [1, 3] [2, 4]    
            if (back[1] >= leftInterval && back[1] < rightInterval) {
                res.pop_back();
                res.push_back({back[0], rightInterval});
            }

        }

        return res;
    }
};