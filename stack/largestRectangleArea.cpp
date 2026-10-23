#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std; 


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = INT_MIN;
        stack<int> st;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int curHeight = (i == n ? 0 : heights[i]);

            while(!st.empty() && heights[st.top()] > curHeight) {
                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                res = max(res, h * width);
            }

            if (i < n) {
                st.push(i);
            }
        }

        return res;
    }
};