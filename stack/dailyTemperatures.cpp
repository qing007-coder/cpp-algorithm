#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std; 


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int j = st.top();
                res[j] = i - j;

                st.pop();
            }

            st.push(i);
        }
        
        return res;
    }
};